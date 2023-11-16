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

	initialise_data(data, argc, argv, env);
	signal(SIGINT, handle_EOF);
	if (is - interactive(ac))
	{
		errno = 2;
		message = MESSAGE;
	}
		errno = 0;
		display_message(message, &info);
		return (0);
}
/**
 * initialise_data - Initializes program data into the structure
 * @data: A pointer to data structure
 * @av: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * @ac: The number of values received from the cmdline
 * Return: Nothing
 */
void initialise_data(ProgramData *data, char **av, char **env, int ac)
{
	unsigned int counter;

	data->program_name = av[0];
	data->input_line = NULL;
	data->comman_named = NULL;
	data->exec_counter = 0;
	data->token = NULL;
	data->token = NULL;
	data->alias_list = NULL;
	if (ac == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(av[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printerr(data->program_name);
			_printerr(" Can't open file");
			_printerr(av[1]);
			_printerr("\n");
			exit(127);
		}
	}
	for (i = 0; environ[i]; i++)
		;
	data->env = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)

		data->env[i] = _strdup(environ[i]);
	data->env[i] = NULL;
	env = data->env;
	data->alias_list = malloc(sizeof(char *) * 50);
	for (i = 0; i < 50; i++)
	{
		data->alias_list[i] = NULL;
	}
}
/**
 * is_interactive - returns true if shell is interactive mode
 * @ac: argument count of the shell
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(int ac)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && ac == 1);
}
/**
 * handle_EOF - Display msg_terminal on a newline when
 * the signal SIGINT is sent to the program.
 * @UNUSED: Signal number (UNUSED, to indicate intentionally unused).
 */
void handle_EOF(int sig UNUSED)
{
	_prinf("\n");
	_printf(MESSAGE);
}
/**
 * display_message - Displays the message loop.
 * @msg_terminal: Printed message.
 * @data: Prompt loop displays.
 */
void display_message(char *msg_terminal, data_of_program *data)
{
	int run = 1;
	int err_code = 0, string_length = 0;

	while (run)
	{
	_printf(msg_terminal);
	err_code = string_length = read_line(data);

	if (err_code == EOF)
	{
		free_everything(data);
		exit(errno); /* if EOF is the first char of string, exit */
	}

	if (string_length >= 1)
	{
		split(data);

		if (data->tokens[0])
		{
		err_code = exec(data);

		if (err_code != 0)
		_print_errors(err_code, data);
		}

	free_tokens_and_input(data);
	}
	}
}

