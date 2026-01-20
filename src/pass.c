#include "pass.h"

pass_t generate_pass(int length, bool hasNumbers, bool hasSymbols) {

    pass_t pass;
    pass.length = length;
    pass.numbers = hasNumbers;
    pass.symbols = hasSymbols;

    const char *letters =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *numbers = "1234567890";
    const char *valid_symbols = ".,-_!()#$[]";

    for (int i = 0; i <= pass.length; i++){
        
    }

    return pass;
}

void load_pass_manager();
void save_pass_manager();
void delete_password();
