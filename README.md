0x16. C - Simple Shell

Learning Objectives

- To designed and implemente the original Unix operating system
- To write the first version of the UNIX shell
- To invente the B programming language (the direct predecessor to the C programming language)
read about Who's Ken Thompson
- To undestand,how does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?



## SIMPLE SHELL FILES##

1. main.h

In main.h, a number of constants, structures, and function prototypes are defined.

- Includes guards are used to prevent multiple inclusions of the header file.
- Several standard library header files are included for necessary functionality.
- Constants are defined for read/write buffer sizes and flushing the buffer.
- Constants represent different types of command chaining and number conversion options.
- Constants determine whether getline() or strtok() should be used for input.
- Constants define the name and size of the history file.
- The global variable `environ` is declared to access environment variables.
- A singly linked list structure called `list_t` is defined, containing a number, a string, and a pointer to the next node.
- A structure called `info_t` is defined, containing various information about the shell program.
- A macro is defined to initialize an instance of `info_t` with default values.
- A structure called `builtin_table` is defined, representing a mapping between a string and a function pointer for built-in commands.
- Function prototypes are provided for functions used in the program.
- The `info_t` struct is used to pass pseudo-arguments to functions.
- The `builtin_table` struct maps strings to corresponding function pointers for built-in commands.
- The code includes various modules/files containing functions for different tasks such as parsing, executing commands, managing memory, and handling errors.
- The main() function is assumed to call the `loophsh()` function to start the shell loop, which reads user input, parses it, and executes commands.

These are function prototypes for actual program functions.
- A uniform prototype for a function pointer struct is made possible by the info_t struct, which defines a set of pseudo-arguments to pass into a function.
- It has a number of fields, including arg and argv for storing command arguments, path for storing the command's path, line_count for counting the number of input lines processed, err_num for storing exit() call error codes, fname for storing the program filename, and environ for storing a customized modified version of the environment variable.

- A mapping between a string expressing a built-in command and the corresponding function to carry out that command is defined by the builtin_table struct.
- The remaining C code consists of a number of modules, including toem_shloop.c, toem_parser.c, loophsh.c, toem_errors.c, toem_string.c, toem_string1.c, toem_exits.c, toem_tokenizer.c, toem_realloc.c, toem_memory.c, toem_atoi. These modules include features for carrying out diverse activities such interpreting user input, running commands, controlling memory, and resolving errors.
Finally, this code fragment does not include the main() function, but it is expected that it will call the loophsh() function to initiate the shell loop. The user's input is read by the loophsh() function, which then analyzes it and issues the appropriate command.


2. main.c

- The main.c  includes the "main.h" header file and defines the main() function as the program's entry point.
- The main() function has two arguments: ac (number of program arguments) and av (an array of strings containing the arguments).
- An array of info_t structures is declared with one element, initialized using the INFO_INIT macro.
- An integer variable fd is declared and initialized to 2.
- There is an inline assembly block that performs bitwise operations on fd.
- If ac is equal to 2, the code attempts to open the file specified by av[1]. If unsuccessful, an error message is printed and the program exits with a specific status code. If successful, the file descriptor is stored in info->readfd.
- The program then calls three functions: populate_env_list(), read_history(), and hsh(), passing the info array and av array.
- Finally, the main() function returns a status code of 0 for success or 1 for error.

3. _atoi.c

- The _atoi.c it defines four functions: interactive, is_delim, _isalpha, and _atoi.
- The "#include "main.h"" directive is used to include the content of the "main.h" header file in the program.
- The "int interactive(info_t *info)" function checks if the shell is running in interactive mode by examining STDIN_FILENO and the readfd field of the info structure. It returns 1 for interactive mode and 0 otherwise.
- The "int is_delim(char c, char *delim)" function determines if a given character c is a delimiter by comparing it to characters in the delim string. It returns 1 for a match and 0 otherwise.
- The "_isalpha(int c)" function checks if a given character c is alphabetic by comparing its ASCII value to the ranges of uppercase and lowercase letters. It returns 1 for an alphabetic character and 0 otherwise.
- The "_atoi(char *s)" function converts a string s into an integer. It iterates through the characters, multiplying the value by 10 and adding the new digit for each numeric character. It stops if a non-numeric character is encountered. It returns 0 if no numeric characters are found and the converted number otherwise.
- These functions provide basic functionality for a shell program, including input parsing and command execution.

4. builtin.c

- The builtin.c it includes three functions for a shell program.
- The "#include "main.h"" directive is used to incorporate the contents of the "main.h" file in the C program, making its declarations available.
- The first function, _myexit, takes a pointer to a structure called info_t as an argument. Its purpose is to exit the shell program. It checks if an argument is passed and attempts to convert it to an integer using _erratoi(info->argv[1]). If successful, it sets info->err_num to the converted integer and returns -2. If there is no argument, it sets info->err_num to -1 and returns -2. If the conversion fails, it sets info->status to 2, prints an error message, and returns 1.
- The second function, _mycd, also takes a pointer to an info_t structure as an argument. Its purpose is to change the current directory of the process. It first obtains the current working directory using getcwd(buffer, 1024). If it fails, it prints a "TODO" message. If no argument is provided, it retrieves the HOME directory using _getenv(info, "HOME="). If the HOME directory is not found, it uses _getenv(info, "PWD=") to get the current directory. It then changes the directory to the obtained directory and sets chdir_ret to the result of chdir(dir). If the argument is "-", it checks for the existence of an environment variable called OLDPWD using _getenv(info, "OLDPWD="). If found, it prints the value of OLDPWD; otherwise, it prints the current working directory. It then changes the directory to the value of OLDPWD or "/" if OLDPWD is not set. For any other argument, it changes the directory accordingly. If the directory change fails, it prints an error message. If successful, it sets the environment variables OLDPWD and PWD to the old and new working directories, respectively, and returns 0.
- The third function, _myhelp, also takes a pointer to an info_t structure as an argument. Its purpose is to display a help message. It assigns info->argv to arg_array and prints a message indicating that the function is not yet implemented. It returns 0.
- These functions implement essential features of a shell program, such as exiting the program, changing directories, and displaying help messages. The info_t structure is used to maintain a consistent function prototype across all the functions in the program.

5. builtin1.c

- The builtin1.c includes several functions used in a shell program.
- _myhistory function:
  - Takes a structure info_t pointer as input and returns an integer.
  - Displays the history list, showing each command on a separate line with line numbers starting from 0.
  - Utilizes the print_list function and doesn't modify the history list.
  - Always returns 0.

- unset_alias function:
  - Takes an info_t structure pointer and a char pointer str as input, returning an integer.
  - Removes an alias from the list.
  - Searches for the position of the '=' character in str using the _strchr function.
  - If the character is not found, it returns 1.
  - Temporarily replaces the '=' character with '\0'.
  - Calls the delete_node_at_index function to remove the node at the corresponding index obtained from get_node_index.
  - Restores the '=' character.
  - Returns the value returned by delete_node_at_index.

- set_alias function:
  - Takes an info_t structure pointer and a char pointer str as input, returning an integer.
  - Sets an alias to a given string.
  - Searches for the position of the '=' character in str using the _strchr function.
  - If the character is not found, it returns 1.
  - If the character immediately after '=' is empty, it calls the unset_alias function with info and str as arguments.
  - Otherwise, it first removes any existing alias with the same name by calling unset_alias.
  - Adds a new node containing str to the end of the alias list in info using the add_node_end function.
  - Returns 0 if the new node is not null, or 1 otherwise.

- print_alias function:
  - Takes a list_t pointer node as input and returns an integer.
  - Prints an alias string.
  - Checks if the node is not null.
  - Searches for the position of the '=' character in node->str using the _strchr function.
  - Loops through the characters in node->str up to that position and prints them using the _putchar function.
  - Prints a single quote character using _putchar.
  - Calls the _puts function with p+1 as an argument to print the rest of the string after '='.
  - Prints a newline character using _puts.
  - Returns 0 if the node is not null, or 1 otherwise.

- The _myalias function is used to create and manipulate aliases within a shell.
- It takes an info_t structure as an argument, which contains potential command-line arguments.

6. environ.c

- The environ.c consists of several functions that relate to manipulating and accessing environment variables.
- int _myenv(info_t *info):
  - This function prints the current environment by calling the print_list_str function, which takes a linked list and prints each node as a string.

- char *_getenv(info_t *info, const char *name):
  - This function retrieves the value of a specified environment variable.
  - It iterates through the env linked list, searching for the first node whose string starts with the specified name.
  - It returns the string starting from the end of the name.

- int _mysetenv(info_t *info):
  - This function sets a new environment variable or modifies an existing one.
  - It takes two arguments: the name and the value.
  - It sets the name to the value in the env linked list.
  - It calls the _setenv function to perform the actual setting of the environment variable.

- int _myunsetenv(info_t *info):
  - This function removes an environment variable.
  - It calls the _unsetenv function for each name passed in as an argument.

- int populate_env_list(info_t *info):
  - This function initializes the env linked list with the values from the environ global variable.
  - It iterates through the environ array and adds each string to the env linked list using the add_node_end function.

7. errors.c

- The errors.c defines several functions for outputting strings and characters to standard error and other file descriptors.
- The first line includes the "main.h" header file, which likely contains necessary function prototypes, constants, and other declarations.
- Function: _eputs
  - This function takes a string as input and prints it to standard error using the _eputchar function.
  - It iterates over each character of the string until it reaches the null terminator ('\0').
  - The purpose of this function is to output error messages to the user.

- Function: _eputchar
  - This function writes a character to standard error.
  - It checks if the character is the BUF_FLUSH constant or if the buffer is full.
  - If either condition is true, it writes the buffer to standard error using the write system call and resets the buffer index.
  - If the character is not BUF_FLUSH, it adds it to the buffer and returns 1.
  - The purpose of this function is to output a single character to standard error.

- Function: _putfd
  - This function is similar to _eputchar but writes a character to a specified file descriptor (fd) instead of standard error.
  - It writes the character to the specified file descriptor.
  - The purpose of this function is to output a single character to a file other than standard error.

- Function: _putsfd
  - This function is similar to _eputs but takes an additional file descriptor (fd) argument.
  - It iterates over each character of the string and writes it to the specified file descriptor using the _putfd function.
  - It returns the number of characters written to the file descriptor.
  - The purpose of this function is to output a string to a file other than standard error.

8. errors1.c

- The errors1.c includes the "main.h" header file, which  contains declarations and definitions of functions, structures, and constants used in the program.

- Function: _erratoi
  - This function converts a string to an integer.
  - It takes a string as input and returns the converted number if valid.
  - If the string does not contain numbers or the converted number is greater than INT_MAX, it returns -1.

- Function: print_error
  - This function prints an error message to standard error output.
  - It takes a structure called info and a string called estr as parameters.
  - The purpose of this function is to handle printing error messages with specified error types.

- Function: print_d
  - This function prints a decimal (integer) number to a specified file descriptor.
  - It takes an integer input and a file descriptor (fd) as parameters.
  - The function returns the number of characters printed.

- Function: convert_number
  - This function converts a number to a string in the specified base.
  - It takes a long integer num, an integer base, and a flags argument as parameters.
  - The function returns a pointer to the converted string.

- Function: remove_comments
  - This function replaces the first instance of a "#" character with a null character.
  - It takes a string buf as input and modifies the string in-place.
  - The function always returns 0.

9.  exits.c

- Function: _strncpy
  - This function copies a string src to dest, copying at most n characters from src.
  - It takes three parameters: dest (destination string), src (source string), and n (number of characters to be copied).
  - The function copies characters from src to dest using a while loop, filling the remaining characters of dest with null characters if necessary.
  - It returns a pointer to the beginning of dest.

- Function: _strncat
  - This function concatenates two strings, src and dest, appending at most n characters from src to dest.
  - It takes three parameters: dest (first string), src (second string), and n (maximum number of bytes to be used).
  - The function appends characters from src to dest using two while loops, and adds a null character to the end of dest if necessary.
  - It returns a pointer to the beginning of dest.

- Function: _strchr
  - This function locates a character c in a string s.
  - It takes two parameters: s (string to be parsed) and c (character to look for).
  - The function searches for c in the string s using a do-while loop.
  - If c is found, it returns a pointer to the memory area in s where c is located. If c is not found, it returns NULL.

10. getLine.c

- Function: input_buf
  - This function buffers chained commands entered by the user in the command line interface.
  - It takes three parameters: info (pointer to info struct), buf (pointer to character buffer), and len (pointer to integer length).
  - It returns the number of bytes read.

- Function: get_input
  - This function retrieves a line of input from the user, excluding the newline character.
  - It takes one parameter: info (pointer to info struct).
  - It returns the number of bytes read.

- Function: read_buf
  - This function reads a buffer and returns the number of bytes read.
  - It takes three parameters: info (pointer to info struct), buf (character buffer), and i (pointer to integer variable).
  - It returns the number of bytes read.

- Function: _getline
  - This function retrieves the next line of input from the standard input (STDIN).
  - It takes three parameters: info (pointer to info struct), ptr (pointer to character pointer), and length (pointer to integer variable).
  - It returns the number of bytes read.

- Function: sigintHandler
  - This function blocks the Ctrl-C signal to prevent the user from accidentally terminating the shell.
  - It takes one parameter: sig_num (integer signal number).

The `#include "main.h"` statement at the beginning of the code file is a preprocessor directive that includes the header file "main.h" in the current code file. The "main.h" header file likely contains function and data structure declarations used in this code file.

11. getenv.c

- Code Function: get_environ
  - This function returns a copy of the environment variables stored in the info structure as a string array.
  - It takes one parameter: info (pointer to info structure).
  - Inside the function, it checks if the info structure contains environment variables. If not, it converts the linked list of environment variables to an array of strings and assigns it to the environ field of the info structure.
  - Finally, it returns the environ field.

- Code Function: _unsetenv
  - This function removes an environment variable named var from the linked list of environment variables stored in the info structure.
  - It takes two parameters: info (pointer to info structure) and var (string containing the name of the environment variable to be removed).
  - Inside the function, a while loop iterates through the linked list and checks if the var string matches the environment variable name. If a match is found, the delete_node_at_index function is called to remove the node from the linked list.
  - Finally, it returns the value of the env_changed field in the info structure.

- Code Function: _setenv
  - This function sets an environment variable named var to the value value in the linked list of environment variables stored in the info structure.
  - It takes three parameters: info (pointer to info structure), var (string containing the name of the environment variable), and value (string containing the value of the environment variable).
  - Inside the function, memory is allocated for the buf variable to hold the concatenated string of the environment variable name and value with an equal sign in between them.
  - Then, a while loop iterates through the linked list and checks if the var string matches the environment variable name. If a match is found, the existing node is updated with the new value. If no match is found, a new node is created at the end of the linked list with the new environment variable.
  - Finally, it returns 0.

The `#include "main.h"` statement at the beginning of the code file is a preprocessor directive that includes the header file "main.h" in the current code file. The "main.h" header file likely contains function and structure declarations used in this code file.

12. getinfo.c

- Code Function: clear_info
  - This function initializes the fields of the info_t structure to NULL or 0.
  - It takes one parameter: info (pointer to info_t structure).
  - Inside the function, it sets the arg, argv, path, and argc fields of the info_t structure to NULL or 0.

- Code Function: set_info
  - This function initializes the fields of the info_t structure.
  - It takes two parameters: info (pointer to info_t structure) and av (argument vector, a vector of strings).
  - Inside the function, it sets the fname field of the info_t structure to the first element of the av vector.
  - If the arg field of the info_t structure is not NULL, it calls the strtow function to split the arg string into an array of strings, which is assigned to the argv field. If strtow returns NULL, it allocates memory for a new argv array with size 2 and assigns the arg string to the first element.
  - The function then counts the number of elements in the argv array and assigns the count to the argc field.
  - It calls the replace_alias and replace_vars functions to perform replacements in the info_t structure.

- Code Function: free_info
  - This function frees the fields of the info_t structure.
  - It takes two parameters: info (pointer to info_t structure) and all (a flag indicating whether to free all fields).
  - Inside the function, it frees the argv and path fields by calling ffree (a custom freeing function).
  - If the all flag is true, it frees additional fields including arg, env, history, alias, environ, cmd_buf. It also closes the file descriptor readfd and flushes the output buffer.

The `#include "main.h"` statement at the beginning of the code file is a preprocessor directive that includes the header file "main.h" in the current code file. The "main.h" header file likely contains function declarations, macros, and data types used in this code file.

13. history.c

- The histrory.c implements a command history feature in a shell program.
- It includes functions for managing the history file location, writing history to a file, reading history from a file, building a linked list of history entries, and renumbering the history after changes.
- The `get_history_file` function retrieves the location of the history file and returns it as a dynamically allocated string.
- The `write_history` function saves the shell's command history to a file by retrieving the history file path and writing each entry to the file.
- The `read_history` function reads the command history from a file, builds a linked list of history entries, and handles various operations such as size checks and node removal.
- The `build_history_list` function adds a line to the history linked list by creating a new node and appending it to the end of the list.
- The `renumber_history` function updates the numbering of history entries after changes have been made.
- Several helper functions are included, such as `_getenv`, `_strlen`, `_strcpy`, `_strcat`, `_putsfd`, `_putfd`, and `add_node_end`.
- These functions work together to manage the command history feature, including retrieving the history file path, writing and reading history to/from the file, manipulating the linked list, and performing string operations.

Additional helper functions include `_getenv` for retrieving environment variable values, `_strlen` for calculating string length, `_strcpy` for copying strings, `_strcat` for concatenating strings, `_putsfd` for writing strings to a file descriptor, `_putfd` for writing characters to a file descriptor, and `add_node_end` for appending nodes to a linked list.

14. lists.c

- The lists.c file presents a C implementation of a linked list data structure and offers various functions for handling the list.
- The linked list is defined using a struct named `list_t`, consisting of three fields: `str` (a pointer to a string value in the node), `num` (an integer used for indexing), and `next` (a pointer to the next node).
- The provided functions are as follows:
  - `add_node`: Adds a new node to the beginning of the linked list, taking a pointer to the head node, a string value, and an integer index as inputs. It returns the updated head of the list.
  - `add_node_end`: Appends a new node to the end of the linked list, accepting a pointer to the head node, a string value, and an integer index as parameters. It returns the newly added node.
  - `print_list_str`: Prints only the string values of each node in the linked list. It takes the head node pointer as input and returns the size of the list.
  - `delete_node_at_index`: Deletes a node at a specified index in the linked list, given the head node pointer and an integer index. It returns 1 if the deletion is successful, or 0 otherwise.
  - `free_list`: Releases the memory allocated for all nodes in the linked list. It accepts the head pointer as input and deallocates the memory for each node.
- In summary, these functions enable the creation, manipulation, and deallocation of a linked list data structure in C.

15. lists1.c

- The lists1.c presents a collection of functions written in C for manipulating linked lists.
- The code begins by including the header file "main.h" which presumably contains function declarations used in this code.
- The function `list_len` calculates the length of a linked list by iterating through it using a while loop. It takes the pointer to the first node as input and returns the size of the list as a `size_t` data type.
- The `list_to_strings` function converts a linked list into an array of strings. It takes the pointer to the first node as input, determines the list's length using `list_len`, allocates memory for the string array, and iterates through the list using a for loop. It copies each node's string value into the array using the `_strcpy` function. Finally, it returns the array of strings.
- The `print_list` function prints the contents of a linked list to the console. It takes the pointer to the first node as input and iterates through the list using a while loop. Each node's numeric value, followed by a colon and space, and the string value (or "nil" if it is null) are printed. The function also returns the size of the list as a `size_t` data type.
- The `node_starts_with` function checks if any node in the linked list, starting from the provided node, has a string value that starts with a given prefix and matches a specified character after the prefix. It iterates through the list using a while loop and calls the `starts_with` function to perform the matching. If a match is found, the current node is returned; otherwise, it moves to the next node. If no node matches, the function returns NULL.
- The `get_node_index` function determines the index of a given node within a linked list. It takes the pointer to the first node and a pointer to the target node as input. It iterates through the list using a while loop, comparing each node to the target node. If a match is found, the index is returned. If no node matches, -1 is returned.



16. memory.c

The function bfree() is a C language function that frees the memory allocated to a pointer.

- The function takes a pointer to a pointer (void **ptr) as its argument.
- The line "if (ptr && *ptr)" checks if ptr is not NULL and if the pointer it points to (*ptr) is also not NULL.
  - If both conditions are true, it means that memory has been allocated to the pointer.
  - The function proceeds to free the memory by calling free(*ptr).
  - It then sets *ptr to NULL to avoid any dangling references.
  - Finally, it returns 1 to indicate success.
- If ptr is NULL or if *ptr is NULL, it means that no memory has been allocated to the pointer.
  - In such cases, the function directly returns 0 to indicate failure.
- The bfree() function is useful for properly deallocating dynamically allocated memory and ensuring that the pointer is set to NULL.
- By returning a status code, the function allows the caller to determine whether the memory was successfully freed or not.

17. parser.c

The breakdown of the three functions related to finding and executing commands in a shell program:

- int is_cmd(info_t *info, char *path)
   - This function takes a pointer to the info_t struct and a char pointer path as arguments and returns an integer.
   - It determines whether the given path corresponds to an executable command by calling the stat() system call on the file path.
   - If the path is a regular file, indicating it is executable, the function returns 1. Otherwise, it returns 0.

- char *dup_chars(char *pathstr, int start, int stop)
   - This function takes a char pointer pathstr and two integers start and stop as arguments and returns a char pointer.
   - It duplicates characters from the pathstr starting from the index specified by start and ending at the index specified by stop.
   - The duplicated characters are stored in a static buffer called buf, and then the buffer is returned as a new string.

- char *find_path(info_t *info, char *pathstr, char *cmd)
   - This function takes a pointer to the info_t struct, a char pointer pathstr containing the PATH environment variable, and a char pointer cmd as arguments. It returns a char pointer.
   - The function searches for the full path of a command by iterating over each ':' separated entry in the pathstr.
   - For each entry, it appends the command name (cmd) to the entry and checks whether it is an executable command using the is_cmd() function.
   - If a matching executable command is found, the full path to the command is returned. Otherwise, NULL is returned.

Overall, these functions are essential for locating and executing commands in a shell program that utilizes the PATH environment variable. The is_cmd() function checks if a given path corresponds to an executable command. The dup_chars() function duplicates characters from a string and returns them as a new string. The find_path() function searches for the full path of a command by iterating over the PATH variable entries and appending the command name to each entry, returning the full path if found.

18. realloc.c

Breakdown of functions and their descriptions:

- `_memset` function:
   - Description: Fills a block of memory with a given value.
   - Arguments: Pointer to the memory block, byte value to fill the memory with, and the number of bytes to be filled.
   - Returns: Pointer to the memory block.
   - Implementation: Uses a for loop to fill each byte of the memory block with the given value.

- `ffree` function:
   - Description: Frees a string of strings.
   - Argument: Pointer to a string of strings.
   - Implementation: Frees each string in the string of strings and then frees the entire string of strings.

- `_realloc` function:
   - Description: Reallocates a block of memory.
   - Arguments: Pointer to the previous block of memory, size of the previous block of memory, and size of the new block of memory.
   - Returns: Pointer to the new block of memory.
   - Implementation:
     - Checks if the pointer is NULL and allocates a new block of memory of the given size if true.
     - If the new size is zero, it frees the previous block of memory and returns NULL.
     - If the new size is the same as the old size, it simply returns the previous block of memory.
     - Otherwise, it allocates a new block of memory of the given size, copies the contents of the old block to the new block, and frees the old block.

19. shell_loop.c

Breakdown of each function in the given code:

- `int hsh(info_t *info, char **av)`
   - Description: The main function that runs the shell loop.
   - Arguments: Pointer to a struct info_t (shell's state information) and an array of strings representing command line arguments.
   - Implementation:
     - Starts a loop to read user input using the `get_input` function.
     - Processes the input by calling the `find_builtin` and `find_cmd` functions.
     - Continues the loop until an error occurs or the user enters the "exit" command.
     - Calls the `write_history` and `free_info` functions to write the history to a file and free allocated memory.
     - Returns the result of the last executed command.

- `int find_builtin(info_t *info)`
   - Description: Searches for a built-in command in the `builtintbl` array.
   - Argument: Pointer to a struct info_t.
   - Returns: The return value of the corresponding built-in command function or -1 if no match is found.
   - Implementation:
     - Searches the `builtintbl` array for a command that matches the first argument in the `argv` array of the `info_t` struct.
     - If a match is found, the corresponding function is called and its return value is returned.
     - If no match is found, -1 is returned.

- `void find_cmd(info_t *info)`
   - Description: Searches for a command in the directories listed in the PATH environment variable.
   - Argument: Pointer to a struct info_t.
   - Implementation:
     - Checks if the first argument in the `argv` array is a valid command by calling the `is_cmd` function.
     - If valid, searches for the command in each directory listed in the PATH variable by calling the `find_path` function.
     - If the command is found, sets the `path` member of the `info_t` struct to the command's path and calls the `fork_cmd` function to execute the command.
     - If the command is not found, prints an error message and sets the `status` member of the `info_t` struct to 127.

- `void fork_cmd(info_t *info)`
   - Description: Forks a child process to execute a command.
   - Argument: Pointer to a struct info_t.
   - Implementation:
     - Calls the `fork` system call to create a new child process.
     - If the fork call fails, prints an error message and returns.
     - If the fork call succeeds, the child process replaces its image with the command by calling the `execve` system call with the path and `argv` members of the `info_t` struct.
     - If the `execve` call fails, prints an error message, and the child process exits with a status code of 1.
     - The parent process waits for the child process to finish executing by calling the `wait` system call and sets the `status` member of the `info_t` struct to the exit status of the child process.

20. string.c

string.c consist of four functions: _strlen(), _strcmp(), starts_with(), and _strcat().Here is a breakdown of each function:

- `_strlen()`
   - Description: Returns the length of a string.
   - Argument: A pointer to a string.
   - Returns: The length of the string.
   - Implementation:
     - Checks if the pointer to the string is null. If null, returns zero.
     - Initializes a counter variable `i` to zero.
     - Uses a while loop to iterate through the string, incrementing `i` until it reaches the end of the string.
     - Returns `i`, which represents the length of the string.

- `_strcmp()`
   - Description: Performs a lexicographic comparison between two strings.
   - Arguments: Two pointers to strings.
   - Returns:
     - If the two strings are equal, returns zero.
     - If the strings are different, returns the difference between the ASCII values of the first differing characters.
   - Implementation:
     - Uses a while loop to iterate through both strings, comparing each character along the way.
     - If a differing character is found, returns the difference between their ASCII values.
     - If the loop completes without finding any differences, returns zero.

- `starts_with()`
   - Description: Checks if the second string starts with the first string.
   - Arguments: Two pointers to strings.
   - Returns:
     - If the second string starts with the first string, returns a pointer to the character immediately following the end of the first string.
     - If the second string does not start with the first string, returns NULL.
   - Implementation:
     - Uses a while loop to iterate through both strings, comparing each character along the way.
     - If a differing character is found, returns NULL.
     - If the loop completes without finding any differences, returns a pointer to the character immediately following the end of the first string in the second string.

- `_strcat()`
   - Description: Concatenates two strings.
   - Arguments: A destination buffer and a source buffer.
   - Returns: A pointer to the beginning of the destination string.
   - Implementation:
     - Uses a while loop to find the end of the destination string.
     - Uses another while loop to append the characters from the source string to the destination string.
     - Returns a pointer to the beginning of the destination string.

21. string1.c

our shell application will use these text manipulation functions and Here's a breakdown of each string manipulation function and its purpose:

- `_strcpy`
   - Description: Copies the contents of the source string to the destination string.
   - Arguments: `dest` (destination string) and `src` (source string).
   - Returns: A pointer to the destination string.
   - Implementation:
     - Checks if the destination and source strings are the same or if the source string is null. If true, returns the destination string.
     - Uses a while loop to iterate through the source string and copies each character to the destination string.
     - Adds a null character at the end of the destination string to terminate it.

- `_strdup`
   - Description: Creates a duplicate of a given string.
   - Argument: A string `str`.
   - Returns: A pointer to the duplicated string.
   - Implementation:
     - Uses a while loop to determine the length of the string.
     - Allocates memory for the new string using dynamic memory allocation.
     - Copies the contents of the original string to the newly allocated memory.
     - Returns a pointer to the duplicated string.

- `_puts`
   - Description: Prints a string to standard output.
   - Argument: A string `str`.
   - Implementation:
     - Checks if the string is null. If true, returns without doing anything.
     - Uses a while loop to iterate through the string and print each character using the `_putchar` function.

- `_putchar`
   - Description: Writes a character to standard output.
   - Argument: A character `c`.
   - Returns: 1 on success, -1 on error.
   - Implementation:
     - Checks if the character is a flush character or if the buffer is full.
     - If true, writes the contents of the buffer to standard output and resets the buffer index.
     - If false, adds the character to the buffer and increments the buffer index.
     - Returns 1 on success and -1 on error.

22. tokenizer.c

The two functions strtow() and strtow2() that divide a string into an array of words based on a designated delimiter are defined by these codes.


- `strtow()`
   - Description: Splits a string into an array of words based on a specified delimiter.
   - Arguments: `str` (input string to split) and `d` (delimiter string).
   - Returns: A pointer to an array of strings.
   - Implementation:
     - Handles edge cases: If `str` is NULL or empty, it returns NULL. If `d` is NULL, it defaults to a space character.
     - Counts the number of words in the input string by iterating through each character and counting each word encountered. A word is defined as a sequence of non-delimiter characters that either ends with a delimiter or is at the end of the string.
     - If there are no words in the string, it returns NULL.
     - Allocates memory for the array of strings based on the number of words counted. It also allocates memory for each individual string in the array.
     - Populates each string in the array by iterating through the input string and copying each character to the corresponding string until it reaches a delimiter or the end of the string. It then adds a null terminator at the end of each string.

- `strtow2()`
   - Description: Splits a string into an array of words based on a specified delimiter character.
   - Arguments: `str` (input string to split) and `d` (delimiter character).
   - Returns: A pointer to an array of strings.
   - Implementation:
     - Handles edge cases: If `str` is NULL or empty, it returns NULL.
     - Counts the number of words in the input string by iterating through each character and counting each word encountered. A word is defined as a sequence of non-delimiter characters that either ends with a delimiter or is at the end of the string.
     - If there are no words in the string, it returns NULL.
     - Allocates memory for the array of strings based on the number of words counted. It also allocates memory for each individual string in the array.
     - Populates each string in the array by iterating through the input string and copying each character to the corresponding string until it reaches a delimiter or the end of the string. It then adds a null terminator at the end of each string.

Both functions follow a similar approach but differ in how the delimiter is handled (as a string or a character). They count the number of words, allocate memory for the array and strings, and populate the strings by copying characters from the input string.

23. vars.c

This  vars.c defines the following functions and includes the header file "main.h":

- `int is_chain(info_t *info, char *buf, size_t *p)`
   - Description: Tests if the current character in the buffer is a chain delimiter.
   - Arguments: `info` (a pointer to a struct containing information about the current command), `buf` (a character buffer containing the current command), `p` (a pointer to the current position in `buf`).
   - Returns: 1 if a chain delimiter is found, 0 otherwise.
   - Implementation: The function checks if the current character is a chain delimiter by comparing it with specific characters defined as chain delimiters in the `info` struct.

- `void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)`
   - Description: Checks if chaining should continue based on the last status of the executed command.
   - Arguments: `info` (a pointer to a struct containing information about the current command), `buf` (a character buffer containing the current command), `p` (a pointer to the current position in `buf`), `i` (the starting position in `buf`), `len` (the length of `buf`).
   - Returns: void.
   - Implementation: The function checks if chaining should continue based on the last command's status. If the last command's status indicates that chaining should continue, it updates the `info` struct accordingly.

- `int replace_alias(info_t *info)`
   - Description: Replaces aliases in the tokenized string.
   - Arguments: `info` (a pointer to a struct containing information about the current command).
   - Returns: 1 if a replacement is made, 0 otherwise.
   - Implementation: The function checks if the command matches an alias in the `info` struct and replaces it with the corresponding alias value.

- `int replace_vars(info_t *info)`
   - Description: Replaces variables in the tokenized string.
   - Arguments: `info` (a pointer to a struct containing information about the current command).
   - Returns: 1 if a replacement is made, 0 otherwise.
   - Implementation: The function checks if the command contains any variables and replaces them with their corresponding values.

- `int replace_string(char **old, char *new)`
   - Description: Replaces a string.
   - Arguments: `old` (a pointer to the old string), `new` (the new string).
   - Returns: 1 if a replacement is made, 0 otherwise.
   - Implementation: The function replaces the string pointed to by `old` with the new string `new`.

Each function has its specific purpose, such as identifying chain delimiters, checking command chaining conditions, replacing aliases, and replacing variables. They operate on the information stored in the `info` struct to perform their respective tasks.

The authors of this content are Benson and Dorcas. It is requested that no editing be done.

