#include "main.h"
/**
 * set_directory - Set the working directory
 * @data: A struct containing the program's data.
 * @new_dir: Path to be set as the working directory.
 * Return: 0 on success, or other number if its specified in the args
 */
int set_directory(ProgramData *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_found = 0;

	getcwd(old_dir, 128);

	if (!_strcompare(old_dir, new_dir, 0))
	{
		err_found = chdir(new_dir);
		if (err_found == -1)
		{
			errno = 2;
			return (3);
		}
		set_env("PWD", new_dir, data);
	}
	set_env("OLDPWD", old_dir, data);
	return (0);
}
/**
 * cd - This change current directory
 * @data: A struct containing the program's data.
 * Return: 0 on Success, or other number if its specified in the args
 */
int cd(ProgramData *data)
{
	char *dir_home = fetch_info("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int err_code = 0;

	if (data->tokens[1])
	{
		if (_strcompare(data->tokens[1], "-", 0))
		{
			dir_old = fetch_info("OLDPWD", data);
			if (dir_old)
				err_code = set_directory(data, dir_old);
			_printf(fetch_info("PWD", data));
			_printf("\n");

			return (err_code);
		}
		else
		{
			return (set_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (set_directory(data, dir_home));
	}
	return (0);
}
/**
 * alias_handler - Manage aliases by adding, removing, or displaying them.
 * @data: A struct containing the program's data.
 * Return: 0 on success, or other number if specified in the args.
 */
int alias_handler(ProgramData *data)
{
	int i = 0;

    /* if there are no arguments, print all aliases */
	if (data->tokens[1] == NULL)
		return (print_alias_info(data, NULL));

	for (i = 1; data->tokens[i] != NULL; i++)
	{
		if (count_occurrences(data->tokens[i], "="))
			add_alias(data->tokens[i], data);
		else
			print_alias_info(data, data->tokens[i]);
	}
	return (0);
}
