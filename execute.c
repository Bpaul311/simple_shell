#include "main.h"

/**
<<<<<<< HEAD
 * execute_command: Executes a command in a child process.
 * @data: A pointer to the program's data.
 * Return: 0 on success, otherwise -1.
=======
 * execute_command - Executes a command in a child process.
 * @command: The command to execute.
 * @arguments: An array of strings representing command-line arguments.
 * @environment: An array of strings representing environment variables.
 *
 * This function executes a command in a child process, using the provided
 * command, arguments, and environment.
>>>>>>> 44e6ecef980ac95bba90a15a2401d8698c1680d8
 */
int execute_command(data_of_program *data)
{
	int return_value = 0, status;
	pid_t pid;

	return_value = find_builtin(data);
	if (return_value != -1)
		return (return_value);

	/* check for program file system */
	return_value = find_prog(data);
	if (return_value)
		return (return_value);
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
		{
<<<<<<< HEAD
			/* I am the child process, I exec the program*/
			return_value = execve(data->tokens[0], data->tokens, data->env);
			if (return_value == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
}
=======
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

	if (WIFEXITED(status))
	{
		printf("Child process exited with status %d\n", WEXITSTATUS(status));
	}
>>>>>>> 44e6ecef980ac95bba90a15a2401d8698c1680d8
		else
		{/* I am the father, I wait and check the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
<<<<<<< HEAD
=======
}

/**
 * main - Entry point of the program.
 *
 * This is the entry point of the program. It sets up the command, arguments,
 * and environment for the execute_command function and calls it.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *command = "/bin/ls";
	char *arguments[] = {"/bin/ls", "-l", NULL};
	char *environment[] = {NULL};

	execute_command(command, arguments, environment);

>>>>>>> 44e6ecef980ac95bba90a15a2401d8698c1680d8
	return (0);
}
