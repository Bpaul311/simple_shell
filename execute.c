#include "main.h"

/**
 * execute_command- Executes a command in a child process.
 * @data: A pointer to the program's data.
 * Return: 0 on success, otherwise -1.
 */

int execute_command(data_of_program *data)
{
	int value = 0, status;
	pid_t pid;

	value = find_builtin(data);
	if (value != -1)
		return (value);

	/* check for program file system */
	value = find_program(data);
	if (value)
		return (value);
	else
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{/* I am the child process, I exec the program*/
			value = execve(data->tokens[0], data->tokens, data->env);
			if (value == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* I am the father, I wait and check the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
