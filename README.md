# Simple Shell Project

![Gates of shell](images/shell.jpeg)

## Overview

This Simple Shell project is a basic implementation of a Unix shell,
designed to provide a command-line interface for users to interact with their operating system.
It's an excellent learning tool for understanding how shells work and for practicing system programming concepts.

## Features

- Basic command execution
- Built-in commands (e.g., cd, exit)
- Environment variable handling
- Path resolution for executables
- Simple error handling

## Files and Their Functions

- `myheader.h`: Header file containing function prototypes and necessary includes
- `main_shell.c`: The main entry point of the shell program
- `prompt_disp.c`: Handles displaying the shell prompt
- `_getline.c`: Implements a custom getline function for reading user input
- `cmd_exec.c`: Manages the execution of commands
- `childpro_exec.c`: Handles child process execution
- `path_finder.c`: Resolves executable paths
- `env_var.c`: Manages environment variables
- `builtin_cmd.c`: Implements built-in commands
- `_chdir.c`: Handles the change directory functionality
- `error.c`: Manages error messages and handling
- `clear_console.c`: Implements console clearing functionality
- `_str.c`, `_strcmp.c`, `_strcat.c`, `_strdup.c`, `_strlen.c`, `_strncat.c`, `_strncmp.c`, `_strncpy.c`: String manipulation functions
- `_putchar.c`: Implements a custom putchar function
- `_stmstr.c`: (Purpose unclear, possibly string-related functionality)

## How to Use

1. Clone the repository to your local machine.
2. Compile the project using a C compiler below:

gcc-Wall -Werror -Wextra -pedantic \*.c -o hsh

3. Run the shell:

./hsh

4. You will see a prompt where you can enter commands.
5. Enter commands as you would in a regular shell. For example:

- `ls -l`: List files in long format
- `cd directory_name`: Change directory
- `touch file_name`: Creates a new file
- `echo`: prints on the screen.
- `clear`: Clears the screen.
- `mkdir directory_name`: creates a new directory
- `rm file_name`: removes/deletes a file
- `rm -r directory_namect`: deletes directory
- `exit`: Exit the shell

## Learning Objectives

By studying and working with this project, you can learn about:

- Process creation and management in Unix-like systems
- File descriptors and I/O operations
- String parsing and manipulation in C
- Environment variable handling
- Basic shell functionalities and how they're implemented

## Author

Lawal Adedamola Olumide

## Contributing

This project is open for improvements and bug fixes. Feel free to fork the repository, make your changes, and submit a pull request.
