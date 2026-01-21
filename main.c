#include "src/pass.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, const char *argv[]) {

    bool hasNumbers = false;
    bool hasSymbols = false;

    if (argc >= 5) {
        printf("Usage: vipass [length] [-n] [-s]\n");
        printf("configurations:\n");
        printf("  -n\t\t add numbers to the pool\n");
        printf("  -s\t\t add symbols to the pool\n");
        return 0;
    }

    if (argc == 1) {
        printf("Generating a password of length 16 bytes\n");
        char *password = (char *)malloc(16);
        generate_pass(password, 16, false, false);
        printf("Generated Password: %s\n", password);

        free(password);
        return 0;
    }

    for (int i = 0; i < argc; i++) {
        int res = strcmp(argv[2], argv[3]);
        if (strcmp(argv[i], "-n") == 0) {
            hasNumbers = true;
        }
        if (strcmp(argv[i], "-s") == 0) {
            hasSymbols = true;
        }
    }

    u_int8_t length = atoi(argv[1]);
    printf("Generating a password of length %d bytes\n", length);

    char *password = (char *)malloc(length);
    generate_pass(password, length, hasNumbers, hasSymbols);
    printf("Generated Password: %s\n", password);

    free(password);
    return 0;
}
