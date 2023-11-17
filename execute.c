#include "main.h"

/**
 * execute_command- Executes a command in a child process.
 * @data: A pointer to the program's data.
 * Return: 0 on success, otherwise -1.
 */
int execute_command(ProgramData *data)
{
	int val = 0, status;
	pid_t pid;

	/* check for program in built ins */
	val = find_builtin(data);
	if (val != -1)/* if program was found in built ins */
		return (val);

	/* check for program file system */
	val = find_program(data);
	if (val)
	{/* if program not found */
		return (val);
	}
	else
	{/* if program was found */
		pid = fork(); /* create a child process */
		if (pid == -1)
		{ /* if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{/* I am the child process, I exec the program*/
			val = execve(data->tokens[0], data->tokens, data->env);
			if (val == -1) /* if error when execve*/
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
