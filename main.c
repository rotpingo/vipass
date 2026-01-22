#include "src/pass.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void helper() {
    printf("Usage: vipass [LENGTH] [-n] [-s]\n");
    printf("configurations:\n");
    printf("  -n\t\t add numbers to the pool\n");
    printf("  -s\t\t add symbols to the pool\n");
}

bool is_number(const char *arg) {
    char *end;
    errno = 0;

    long value = strtol(arg, &end, 10);
    // no digits
    if (end == arg) {
        return false;
    }
    // trailing junk
    if (*end != '\0') {
        return false;
    }
    // overflow
    if (errno == ERANGE) {
        return false;
    }
    // *out = value;
    return true;
}

int main(int argc, const char *argv[]) {

    bool hasNumbers = false;
    bool hasSymbols = false;
    bool length_exist = false;
    u_int8_t length = 16;

    for (int i = 1; i < argc; i++) {

        if (argv[i][0] == '-') {

            if (strcmp(argv[i], "-n") == 0) {
                hasNumbers = true;
            } else if (strcmp(argv[i], "-s") == 0) {
                hasSymbols = true;
            } else {
                fprintf(stderr, "Unknown option: %s\n", argv[i]);
                helper();
                return 1;
            }
        } else {

            if (length_exist) {
                fprintf(stderr, "Length can be set just once\n");
                return 1;
            }

            if (!(is_number(argv[i]))) {
                fprintf(stderr, "Invalid length\n");
                return 1;
            } else {
                length_exist = true;
            }
        }
    }

    if (length_exist) {
        for (int i = 1; i < argc; i++) {
            if (is_number(argv[i])) {
                length = atoi(argv[i]);
                printf("Generating a password of length %d bytes\n", length);
                char *password = (char *)malloc(length + 1);
                if (!password) {
                    perror("malloc");
                    return 1;
                }
                generate_pass(password, length, hasNumbers, hasSymbols);
                printf("Generated Password: %s\n", password);
                free(password);
                return 0;
            }
        }
    }

    printf("Generating a password of length %d bytes\n", length);

    char *password = (char *)malloc(length+1);
    if (!password) {
        perror("malloc");
        return 1;
    }
    generate_pass(password, length, hasNumbers, hasSymbols);
    printf("Generated Password: %s\n", password);
    free(password);
    return 0;
}
