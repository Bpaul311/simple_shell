#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Executes a command in a child process.
 * @command: The command to execute.
 * @arguments: An array of strings representing command-line arguments.
 * @environment: An array of strings representing environment variables.
 *
 * This function executes a command in a child process, using the provided
 * command, arguments, and environment.
 */

void execute_command(char *command, char *arguments[], char *environment[])
{

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

	if (pid == 0)
	{
		if (execve(command, arguments, environment) == -1)
		{
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
		else
		{
			printf("Child process terminated abnormally\n");
		}
	}
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

	return (0);
}
