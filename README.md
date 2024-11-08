# If-Else Compiler Project

## Description

This project is a simple parser that processes if-else statements written in a C-like syntax. The goal of the program is to simulate a basic compiler-like process for understanding and validating the structure of an if-else block, including verifying proper syntax such as parentheses, braces, and keywords.

The program takes an input string that contains a C-like if-else statement and parses it step by step, ensuring that all components are correctly structured. If any errors are encountered, appropriate error messages are displayed.

## Features

- **Keyword Matching**: Verifies the presence of keywords such as `if` and `else`.
- **Parentheses Validation**: Ensures that conditions are enclosed within parentheses `()`.
- **Block Parsing**: Handles the block of code within braces `{}` for the `if` and `else` parts.
- **Error Handling**: Provides error messages for any missing or mismatched components, such as missing parentheses or braces.

## How It Works

1. **Input Processing**: The user is prompted to input a C-like if-else statement.
2. **Keyword Matching**: The program checks for the presence of the `if` keyword, followed by the condition in parentheses.
3. **Block Parsing**: After detecting the condition, the program expects a block of code enclosed within `{}`.
4. **Else Handling**: If an `else` keyword is present, the program checks for its corresponding block and validates the syntax.
5. **Error Reporting**: If there are any errors (e.g., missing parenthesis, missing braces, etc.), the program prints an error message and stops further parsing.

## Prerequisites

- C compiler (e.g., GCC or Clang)

## How to Run

1. **Clone the repository**:

    ```bash
    git clone https://github.com/yourusername/if-else-compiler.git
    ```

2. **Navigate to the project directory**:

    ```bash
    cd if-else-compiler
    ```

3. **Compile the program using a C compiler (e.g., GCC)**:

    ```bash
    gcc -o ifelsecompiler ifelsecompiler.c
    ```

4. **Run the compiled program**:

    ```bash
    ./ifelsecompiler
    ```
