#include <stdio.h>
#include "data.h"
#include "option.h"

void printout(int argc, char *argv[], Data *data, Option *option)
{
    printf("# --- %s %s ---\n", argv[0], option->info);
    printf("# flags: -k %f\n", option->times);

    for (int i = 0; i < data->num; i++)
    {
        for (int j = 0; j < data->dim; j++)
        {
            printf("%f ", data->v[i][j]);
        }
        printf("\n");
    }

    return;
}