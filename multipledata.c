#include <stdlib.h>
#include "data.h"
#include "option.h"

Data *multipledata(Data *data, Option *option)
{
    for (int i = 0; i < data->num; i++)
    {
        for (int j = 0; j < data->dim; j++)
        {
            data->v[i][j] *= option->times;
        }
    }

    return data;
}