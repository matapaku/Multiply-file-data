#include <stdlib.h>
#include "data.h"
#include "option.h"

// グローバルポインタの宣言
extern struct Data *data;
extern struct Option *option;

void free_registors()
{
    // Data構造体のメモリを解放
    free(data);

    // Option構造体のメモリを解放
    free(option);
}
