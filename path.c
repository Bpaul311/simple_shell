#include "main.h"

/**
 * find_file - checks if a file exist, not a directory and
 * it has excecution permissions.
 * @full_path: A pointer to the full filename.
 * Return: 0 on success, or error code if it exists.
 */
int find_file(char *full_path)
{
	struct stat st;

	if (stat(full_path, &st) != -1)
	{
		if (S_ISDIR(st.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/*if not exist the file*/
	errno = 127;
	return (127);
}
