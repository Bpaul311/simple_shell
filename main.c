#include "main.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[], char *env[])
{

	ProgramData data_struct = {NULL}, *data = &data_struct;
	char *message = "";

	initialise_data(data, argv, env, argc);
	signal(SIGINT, handle_EOF);
	if (is_interactive(argc))
	{
		errno = 2;
		message = MESSAGE;
	}
		errno = 0;
		display_message(message, data);
		return (0);
}
/**
 * initialise_data - Initializes program data into the structure
 * @data: A pointer to data structure
 * @argv: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * @argc: The number of values received from the cmdline
 * Return: Nothing
 */
void initialise_data(ProgramData *data, char **argv, char **env, int argc)
{
	unsigned int counter;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	data->tokens = NULL;
	data->alias_list = NULL;
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_print_err(data->program_name);
			_print_err(" Can't open file");
			_print_err(argv[1]);
			_print_err("\n");
			exit(127);
		}
	}
	for (counter = 0; env[counter]; counter++)
		;
	data->env = malloc(sizeof(char *) * (counter + 1));
	for (counter = 0; env[counter]; counter++)

		data->env[counter] = _str_duplicate(env[counter]);
	data->env[counter] = NULL;
	env = data->env;
	data->alias_list = malloc(sizeof(char *) * 50);
	for (counter = 0; counter < 50; counter++)
	{
		data->alias_list[counter] = NULL;
	}
}
/**
 * is_interactive - returns true if shell is interactive mode
 * @argc: argument count of the shell
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(int argc)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1);
}
/**
 * handle_EOF - Display msg_terminal on a newline when
 * the signal SIGINT is sent to the program.
 * @UNUSED: Signal number (UNUSED, to indicate intentionally unused).
 */
void handle_EOF(int sig UNUSED)
{
	_printf("\n");
	_printf(MESSAGE);
}
/**
 * display_message - Displays the message loop.
 * @msg_terminal: Printed message.
 * @data: Prompt loop displays.
 */
void display_message(char *msg_terminal, ProgramData *data)
{
	int err_code = 0, string_length = 0;

	while (++(data->exec_counter))
	{
		_printf(msg_terminal);
		err_code = string_length = read_line(data);
		if (err_code == EOF)
		{
			free_everything(data);
			exit(errno);
		}
		if (string_length >= 1)
		{
			expand_variables(data);
			split(data);
			if (data->tokens[0])
			{
				err_code = execute_command(data);
				if (err_code != 0)
					print_error_message(err_code, data);
			}
			free_tokens_and_input(data);
		}
	}
}
