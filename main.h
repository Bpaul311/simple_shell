#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <stddef.h>

/*define some important  macros */
#define BUFSIZE 1024
#define MESSAGE "$ " 
#define UNUSED __attribute__((unused))

/**
 * struct info - Structure for the program's data
 * @name: The name of the executable
 * @input_line: Pointer to the input read for _getline
 * @command: Pointer to the first command typed by the user
 * @exec_num: Number of executed commands
 * @file_descriptor: File descriptor to the input of commands
 * @tokens: Pointer to an array of tokenized input
 * @env: Copy of the environment variables
 * @alias_list: Array of pointers with aliases
 */

typedef struct info {
    char *name;
    char *input_line;
    char *command;
    int exec_num;
    int file_descriptor;
    char **tokens;
    char **env;
    char **alias_list;
}ProgramData;

/* built-in function structure */
/**
 * Structure for built-in functions
 *
 * @param func_name: Name of the built-in function
 * @param function: Pointer to the function implementation
 */
typedef struct builtin_func
{
	char *func_name;
	int (*function)(ProgramData *data);
} builtin_t;

/*======== function_strings.c ========*/
int _strlen(const char *s); 
int _strcmp(char *str1, char *str2);
void rev_string(char *s);
char *_strcat(char *destination, const char *source);
char *_str_duplicate(char *str);

/*======== num_strings.c ========*/
int num_of_digits(int num);
char *itoa(int num);
int _atoi(char *str);
int count_occurrences(char *str, char *ch);


#endif
