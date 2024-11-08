#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printError(const char* message) {
    printf("Error: %s\n", message);
}

int skipSpaces(char* input, int i) {
    while (isspace(input[i])) i++;
    return i;
}


int matchKeyword(char* input, int i, const char* keyword) {
    int len = strlen(keyword);
    if (strncmp(&input[i], keyword, len) == 0) {
        return i + len;
    }
    printError("Expected keyword missing");
    return -1;
}


int matchChar(char* input, int i, char expectedChar) {
    if (input[i] == expectedChar) {
        return i + 1;
    }
    char message[50];
    sprintf(message, "Missing '%c'", expectedChar);
    printError(message);
    return -1;
}


int parseBlock(char* input, int i) {
    i = matchChar(input, i, '{');
    if (i == -1) return -1;

    while (input[i] != '}' && input[i] != '\0') i++;
    
    if (input[i] != '}') {
        printError("Missing closing brace for block");
        return -1;
    }
    return i + 1;
}

void processIfElseStatement(char* input) {
    int i = 0;

    
    i = matchKeyword(input, i, "if");
    if (i == -1) return;
    
    i = skipSpaces(input, i);

    
    i = matchChar(input, i, '(');
    if (i == -1) return;

    
    while (input[i] != ')' && input[i] != '\0') i++;

    if (input[i] != ')') {
        printError("Missing close parenthesis after condition");
        return;
    }
    i++;  
    i = skipSpaces(input, i);

    
    i = parseBlock(input, i);
    if (i == -1) return;

    i = skipSpaces(input, i);

    
    if (strncmp(&input[i], "else", 4) == 0) {
        i += 4;
        i = skipSpaces(input, i);

        
        i = parseBlock(input, i);
        if (i == -1) return;
        
        printf("If-else statement processed successfully.\n");
    } else {
        printError("'else' keyword expected.");
    }
}

int main() {
    char input[256];
    printf("Enter a C-like if-else statement: ");
    fgets(input, sizeof(input), stdin);
    
    processIfElseStatement(input);

    return 0;
}
