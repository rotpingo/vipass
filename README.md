#### This is a simple CLI password generator

- cryptographically secure
- add symbols and numbers to create more complex password

##### Installation

Download the source code to your machine.

To run it, you need to compile it first using a C compiler
for example gcc.

Open the terminal, navigate to the project folder and do the following:

`gcc main.c src/pass.c -o vipass`

##### Usage

While you are still in the project folder, run the compiled file via command

`./vipass`

which will generate a password by default with a length of 16 characters.

You can specify it to also use numbers and symbols.

Example of generating a password of length 22 with symbols and numbers:

`./vipass 22 -n -s`

To call the help function, use the "-h" flag:

`./vipass -h`
