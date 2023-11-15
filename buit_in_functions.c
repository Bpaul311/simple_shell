#include "main.h"
/**
 * custom_exit- exits the shell
 * @data: the data structure
 * Return: 0 on success
 */
int custom_exit(data_of_program *data)
{
    int i;

    if (data->tokens[1])
    {
        i = 0;
        while (data->tokens[1][i])
        {
            if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9') && data->tokens[1][i] != '+')
            {
                err_num = 2;
                return (2);
            }
            i++;
        }
        err_num = _atoi(data->tokens[1]);
    }

    free_everything(data);
    exit(errno);
}

