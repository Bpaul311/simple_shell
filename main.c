#include "main.h"
/**
 * main - Entry point for the simple shell program.
 * @ac: Number of command-line arguments.
 * @av: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * Return: 0 on success, non-zero on failure.
 */
int main(int ac, char **av, char **env)
{
    ProgramData info = {NULL};
    char message = "";

    initialise_data(&info, argc, argv, env);
    signal(SIGINT, handle_EOF);
    if (is-interactive(ac))
    {
	    err_num = 2;
	    message = MESSAGE;
    }
    else{
	    err_num = 0;


    read_line(&info);

    return 0;
}
/**
 * initialise_data - Initializes program data into the structure
 * @data: A pointer to data structure
 * @av: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * @ac: The number of values received from the cmdline
 * Return: Nothing
 */
void initialise_data(ProgramData *data; char **av; char **env, int ac)
{
	unsigned int counter; 

        data->name = av[0];
	data->input = NULL;
	data->command = NULL;
	data->exec_num = 0;
	data->status  = 0;
	data ->token = NULL;
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
	data->pid = itoa(getpid());
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
 */
void handle_EOF(int sig)
{
	_prinf("\n");
	_printf(MESSAGE);
}
void read_line(ProgramData *Data)
{
	char *copy_command = NULL, *full_command = NULL;
	ssize_t chars_read = 0;
	char *token;
	size_t buffer = 0;
	char *delim = " \t";
	int num_of_tokens = 0;
	int counter;
	char **av;

	while (1)
	{

		print(MESSAGE);
		chars_read = getline(&full_command, &buffer, stdin);
		if (chars_read == -1)
		{
			printf("Exiting shell ...\n");
			break;  
		}
	else
	{
		copy_command = malloc(sizeof(char) * chars_read);
			if (copy_command == NULL)
			{
				perror("failed to allocate memory\n");
				break;
			}
		copy_command = strdup(full_command);
		token = strtok(full_command, delim);
		while (token != NULL)
		{
			num_of_tokens++;
			token = strtok(NULL, delim);
		}
		num_of_tokens++;
		av = malloc(sizeof(char *) * num_of_tokens);
		token = strtok(copy_command, delim);
		for (counter = 0; token != NULL; counter++)
		{
			av[counter] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(av[counter], token);
			token = strtok(NULL, delim);
		}
		av[counter] = NULL;
		for (int i = 0; i < counter; i++)
		{
			free(av[i]);
		}
		free(av);
		free(full_command);
		free(copy_command);
		}
	}
}
