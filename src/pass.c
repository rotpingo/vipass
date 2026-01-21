#include "pass.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

pass_t generate_pass(char *mem, u_int8_t length) {

    const char *letters =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *numbers = "1234567890";
    const char *valid_symbols = ".,-_!()#$[]";

    const char *path_stream = "/dev/urandom";
    FILE *file = fopen(path_stream, "r");
    if (file == NULL) {

        printf("\nCould not open %s\n", path_stream);
        exit(1);
    }

    int c = fgetc(file);
    if (c == EOF) {
        printf("\nCould not read %p\n", file);
        exit(1);
    }

    int pass_length = 0;
    do {
        char a = fgetc(file);
        for (int i = 0; i < 52; i++) {
            if (a == letters[i]) {
                *(mem + pass_length) = a;
                pass_length++;
                continue;
            }
        }
        
    } while (pass_length < length);

    pass_t pass;
    pass.length = length;
    // pass.numbers = hasNumbers;
    // pass.symbols = hasSymbols;
    return pass;
}

void load_pass_manager();
void save_pass_manager();
void delete_password();
