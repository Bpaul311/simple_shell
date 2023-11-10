#include "main.h"
/**
 * main - Entry point for the simple shell program.
 * @ac: Number of command-line arguments.
 * @av: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * Return: 0 on success, non-zero on failure.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>


void read_line(ProgramData *Data)
{
	char *full_command = NULL, *copy_command = NULL;
	ssize_t chars_read = 0;
	char *token;
	size_t buffer = 0;
	char *delim = " ";
	int num_of_tokens = 0;
	int counter;
	char **av;

	printf("$ ");
	chars_read = getline(&full_command, &buffer, stdin);
	if (chars_read == -1)
		{
	printf("Exiting shell ...\n");
	}
	else
	{
		copy_command = malloc(sizeof(char) * chars_read);
			if (copy_command == NULL)
			{
				printf("failed to allocate memory\n");
				return;
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

int main(int ac, char **av, char **env)
{
    ProgramData info = {NULL};
    read_line(&info);
    return 0;
}
