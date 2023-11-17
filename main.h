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
#define BUFFERSIZE 1024
#define MESSAGE "$ "
#define UNUSED __attribute__((unused))
/**
 * struct info - Structure for the program's data
 * @program_name: The name of the executable
 * @input_line: Pointer to the input read for _getline
 * @command_name: Pointer to the first command typed by the user
 * @exec_counter: Number of executed commands
 * @file_descriptor: File descriptor to the input of commands
 * @tokens: Pointer to an array of tokenized input
 * @env: Copy of the environment variables
 * @alias_list: Array of pointers with aliases
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} ProgramData;

/**
 * struct builtin_t - struct for the builtins
 * @func_name: Name of the built-in function
 * @function: Pointer to the function implementation
 */
typedef struct builtin_t
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
int _strcompare(char *string1, char *string2, int number);
/*======== num_strings.c ========*/
int num_of_digits(int num);
char *itoa(int num);
int _atoi(char *str);
int count_occurrences(char *str, char *ch);
void converter(long num, char *string, int base);
/*======== alliasses.c ========*/
int append_string(char *buffer, char *str_to_add);
int print_alias_info(ProgramData *data, char *alias);
char *retrieve_alias_value(ProgramData *data, char *alias);
int add_alias(char *alias_name, ProgramData *data);
/*======== freeing.c ========*/
void free_pointers_array(char **pointers_array);
void free_tokens_and_input(ProgramData *data);
void free_everything(ProgramData *data);
/*======== print_functions.c ========*/
int _printf(char *str);
int _print_err(char *str);
/*========  readline.c  ========*/
int read_line(ProgramData *data);
int split_logical_operators(char *commands_array[], int i,
		char operators_array[]);
int split_and_duplicate(char *commands_array[], int i,
		int j, char operators_array[], char operator);
/*======== tokenize.c ========*/
void split(ProgramData *data);
char *str_tok(char *line, char *delim);
/*======== environment.c ========*/
char *fetch_info(char *name, ProgramData *data);
int env_remove_key(char *key, ProgramData *data);
int set_env(char *name, char *value, ProgramData *data);
void print_env(ProgramData *data);
/*======== main.c  ========*/
void handle_EOF(int sig UNUSED);
void display_message(char *msg_terminal, ProgramData *data);
int is_interactive(int ac);
void initialise_data(ProgramData *data, char **av, char **env, int ac);
/*======== find_errors.c  ========*/
void print_common_error(ProgramData *data, char *n_as_string);
void print_specific_error(ProgramData *data, int errorcode);
void print_error_message(int errorcode, ProgramData *data);
/*======== builtins.c  ========*/
int Display_env(ProgramData *data);
int builtin_set_env(ProgramData *data);
int unset_env(ProgramData *data);
int custom_exit(ProgramData *data);
int find_builtin(ProgramData *data);
int alias_handler(ProgramData *data);
int cd(ProgramData *data);
/*======== execute.c  ========*/
int execute_command(ProgramData *data);
/*======== freeing.c  ========*/
void free_everything(ProgramData *data);
void free_tokens_and_input(ProgramData *data);
void free_pointers_array(char **pointers_array);
/*======== path.c  ========*/
int find_program(ProgramData *data);
char **find_path(ProgramData *data);
int find_file(char *full_path);
#endif
