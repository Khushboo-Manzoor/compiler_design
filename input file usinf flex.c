#include <stdio.h>
%}

%%

[0-9]+     { printf("NUMBER: %s\n", yytext); }    // Detect numbers
[a-zA-Z_][a-zA-Z0-9_]*   { printf("IDENTIFIER: %s\n", yytext); }  // Detect identifiers
[+\-*/=]   { printf("OPERATOR: %s\n", yytext); }  // Detect operators
[;,.()]    { printf("SYMBOL: %s\n", yytext); }    // Detect symbols
\n         { /* Ignore newlines */ }
[ \t]+     { /* Ignore spaces and tabs */ }
.          { printf("UNKNOWN: %s\n", yytext); }  // Handle unknown characters

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("Error opening file: %s\n", argv[1]);
            return 1;
        }
        yyin = file;  // Set input file
    }
    yylex();  // Start lexical analysis
    return 0;
}

int yywrap() {
    return 1;
}
