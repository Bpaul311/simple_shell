#include "main.h"
/**
 * main - Entry point for the simple shell program.
 * @ac: Number of command-line arguments.
 * @av: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * Return: 0 on success, non-zero on failure.
 */

	initialise_data(&info, argc, argv, env);
	signal(SIGINT, handle_EOF);
	if (is - interactive(ac))
	{
		err_num = 2;
		message = MESSAGE;
	}
		else
		{
			err_num = 0;


	read_line(&info);
			read_line(&info);

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

	data->name = av[0];
	data->input = NULL;
	data->command = NULL;
	data->exec_num = 0;
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
 * handle_EOF - Display msg_terminal on a newline
 * when the signal SIGINT (ctrl + c) is sent to the program
 * @UNUSED: it's there for the prototype.
 * @sig: signal number
 */
void handle_EOF(int sig UNUSED)
{
	_prinf("\n");
	_printf(MESSAGE);
}
/**
 * display_message - Dispalys the message loop
 * @msg: Printed msg_terminal
 * @data: Prompt loop displays
 */
void display_message(char *msg_terminal, data_of_program *data)
{
	int run = 1;
	int err_code = 0, string_length = 0;

	while (run)
	{
		_printf(msg);
		err_code = string_length = read_line(data);
		if (err_code == EOF)
		{
			free_everything(data);
			exit(errno); /* if EOF is the fisrt Char of string, exit*/
		}
		if (string_length >= 1)
		{
			split(data);
			if (data->tokens[0])
			{ /* if a text is given to msg_terminal, exec */
				err_code = execute(data);
				if (err_code != 0)
					_print_error(err_code, data);
			}
			free_recurrent_data(data);
		}
	}
}
