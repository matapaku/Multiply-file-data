#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "option.h"

// グローバルポインタの宣言
extern Data *data;
extern Option *option;

void get_registors()
{
    // 構造体用メモリを確保
    data = (Data *)malloc(sizeof(Data));
    if (data == NULL)
    {
        fprintf(stderr, "Data 構造体のメモリの確保に失敗しました.\n");
        exit(1);
    }

    option = (Option *)malloc(sizeof(Option));
    if (option == NULL)
    {
        fprintf(stderr, "Option 構造体のメモリの確保に失敗しました.\n");
        free(data); // 先に確保したメモリを解放
        exit(1);
    }

    // メモリ初期化
    data->dim = 0;
    data->num = 0;
    data->v = NULL;
    option->times = 1.0; // デフォルト値
    option->info = NULL;

    return;
}
