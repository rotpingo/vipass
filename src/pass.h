#pragma once

#include <stdbool.h>
#include <sys/types.h>

/*
 * pass_t is the datatype holding the data about pasword
 *
 * password - actual generated password
 * length - the length of the password
 * numbers - use of numbers
 * symbols - use of symbols
 */

typedef struct {
    const char *pass;
    int length;
    bool numbers;
    bool symbols;
} pass_t;

/*
 *  pass_manager_t will be the datatype storing the info
 *  about the host/site/program which is holding the
 *  generated password
 *
 *  host - name of the site/program/
 *  account_name - Email or login data
 *  password - the generated password that is to be generated
 */
typedef struct {
    const char *host;
    const char *account_name;
    pass_t password;
} pass_manager_t;

pass_t generate_pass(char* mem, u_int8_t length, bool hasNumbers, bool hasSymbols);
void load_pass_manager();
void save_pass_manager();
void delete_password();
