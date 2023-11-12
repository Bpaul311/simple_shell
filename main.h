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

#define SOME_IMPORTANT_MACO
#define MESSAGE "$ "


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
 * @status : the status of our shell.
 */

typedef struct info
{
	char *name;
	char *input_line;
	char *command;
	int exec_num;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
	int status;
} ProgramData;

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

/* String Function */
char *_strdup(const char *s);
int _strlen(const char *s);
#endif
