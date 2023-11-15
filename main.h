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

/*======== alliasses.c ========*/
int append_string(char *buffer, char *str_to_add);
int print_alias_info(data_of_program *data, char *alias);
char *retrieve_alias_value(data_of_program *data, char *alias);
int add_alias(char *alias_name, data_of_program *data);

/*======== freeing.c ========*/
void free_pointers_array(char **pointers_array);
void free_tokens_and_input(data_of_program *data);
void free_everything(data_of_program *data);

/*======== print_functions.c ========*/
int _printf(char *str);
int _print_err(char *str);

/*========  readline.c  ========*/
int read_line(data_of_program *data);
int split_logical_operators(char *commands_array[], int i, char operators_array[]);
int split_and_duplicate(char *commands_array[], int i, int j, char operators_array[], char operator);

/*======== tokenize.c ========*/
void split(data_of_program *data);
char *str_tok(char *line, char *delim);


/*======== environment.c ========*/
int env_remove_key(char *key, data_of_program *data);
char *set_env(char *name, data_of_program *data, int value);
void print_env(data_of_program *data);

/*======== main.c  ========*/
void handle_EOF(int sig UNUSED);
void display_message(char *msg_terminal, data_of_program *data);
int is_interactive(int ac);
void initialise_data(ProgramData *data, char **av, char **env, int ac);

/*======== find_errors.c  ========*/
void print_common_error(data_of_program *data, char *n_as_string);
void print_specific_error(data_of_program *data, int errorcode);
void print_error_message(int errorcode, data_of_progrram *data);


#endif
