#include "main.h"
int main(int argc, char *argv[], char *env[])
{
	char *msg = "";
	ProgramData Data = {NULL};
	
	initialize_data(&Data, argc, argv, env);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	/* its in interactive mode /
		interactive_mode(Data);

