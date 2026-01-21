#include "src/pass.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, const char *argv[]) {

    if (argc != 2) {
        printf("Usage: vipass LENGTH ");
        return 0;
    }

    u_int8_t length = atoi(argv[1]);
    printf("Generating a password of length %d bytes\n", length);

    char *password = (char *)malloc(length);
    generate_pass(password, length);
    printf("Generated Password: \n%s\n", password);

    free(password);
    return 0;
}
