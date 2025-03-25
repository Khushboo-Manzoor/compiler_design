
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200

int main() {
    char str[MAX_LENGTH], delimiters[MAX_LENGTH];
    
    // Get the input string from the user
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Get the delimiter characters from the user
    printf("Enter delimiters (e.g., space, comma, semicolon): ");
    fgets(delimiters, MAX_LENGTH, stdin);
    delimiters[strcspn(delimiters, "\n")] = '\0';

    // Tokenize the string using strtok()
    char *token = strtok(str, delimiters);
    
    printf("\nTokens:\n");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}
