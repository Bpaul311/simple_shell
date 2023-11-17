#include "main.h"
/**
 * expand_variables - It Expand variables.
 * @data: A pointer to a structure of the program's data
 *
 * Return: nothing, but sets errno.
 */
void expand_variables(ProgramData *data)
{
	int i, j;
	char line[BUFFERSIZE] = {0}, expansion[BUFFERSIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	append_string(line, data->input_line);
	for (i = 0; line[i]; i++)
		if (line[i] == '#')
			line[i--] = '\0';
		else if (line[i] == '$' && line[i + 1] == '?')
		{
			line[i] = '\0';
			converter(errno, expansion, 10);
			append_string(line, expansion);
			append_string(line, data->input_line + i + 2);
		}
		else if (line[i] == '$' && line[i + 1] == '$')
		{
			line[i] = '\0';
			converter(getpid(), expansion, 10);
			append_string(line, expansion);
			append_string(line, data->input_line + i + 2);
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			continue;
		else if (line[i] == '$')
		{
			for (j = 1; line[i + j] && line[i + j] != ' '; j++)
				expansion[j - 1] = line[i + j];
			temp = fetch_info(expansion, data);
			line[i] = '\0', expansion[0] = '\0';
			append_string(expansion, line + i + j);
			temp ? append_string(line, temp) : 1;
			append_string(line, expansion);
		}
	if (!_strcompare(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = _str_duplicate(line);
	}
}

