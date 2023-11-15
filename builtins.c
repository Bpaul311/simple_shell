#include <stdio.h>


int builtin_exit(data_of_program *data)
{

    printf("Exiting...\n");

    return (0);
}

int builtin_alias(data_of_program *data)
{
    printf("Executing alias command...\n");

    return 0;
}

int builtin_t_list(data_of_program *data)
{

    int counters;

    builtin_t operators[] = {
        {"exit", builtin_exit},
        {"alias", builtin_alias},
        {NULL, NULL}
    }
};

for (counters = 0; operators[counters].func_name != NULL; counters++)
    {
        if (_strcmp(operators[counters].func_name, data->command))
        {
            return (operators[counters].function(data));
        }
    }
    
    return (-1);
