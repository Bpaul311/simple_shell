#include "main.h"
/**
 * main - Entry point for the simple shell program.
 * @ac: Number of command-line arguments.
 * @av: Array of strings containing the command-line arguments.
 * @env: Array of strings containing the environment variables.
 * Return: 0 on success, non-zero on failure.
 */
void read_line(ProgramData *Data)
{
char *full_command = NULL, copy_command = NULL;
ssize_t chars_read = 0;
char *token;
size_t  buffer = 0;
const char *delim = " ";
int num_of_token = 0;
int counter;

printf("$ ");
chars_read = getline(&full_command, &buffer, stdin);
if (chars_read == -1)
{
	printf("Exiting shell ...\n");
	return (-1);
}
else
{
copy_command = malloc(sizeof(char) *chars_read);
if (copy_command == NULL)
{
	printf("failed to allocate memmory\n");
	return (-1);
}
copy_command = strdup(full_command);
token = _strtok(full_command, delim);
while (token != NULL)
{
	num_of_tokens++;
	token = _strtok(NULL, delim);
}
num_of_token++;
av = malloc(sizeof(char*) *num_of_token);
token = _strtok(copy_command, delim);
for (counter = 0;token != NULL; counter ++)
{
	av[i] = malloc (sizeof(char) *strlen(token));
	av[i] = strdup(token);
	token = strtok(NULL, delim);
}
av[i] = NULL;
free (av);
free (full_command);
free(copy_command);
}
}
int main(int ac, char **av, char **env)
{
	ProgramData info = {NULL};
	read_line(&info);
 
