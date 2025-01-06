#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inout.h"
#include "data.h"
#include "option.h"

/* データ用構造体とオプション用構造体 */
struct Data *data;
struct Option *option;

int main(int argc, char *argv[])
{
    /* まず，*data と *option の領域を確保する．*/
    get_registors();

    /* オプションを読みとる．*/
    option = getoption(argc, argv, option);

    /* 入力データを読み込む．*/
    data = getdata(data);

    /* 入力データを定数倍する．*/
    data = multipledata(data, option);

    /* 結果を出力する */
    printout(argc, argv, data, option);

    /* get_registors() で確保した領域を解放する．*/
    free_registors();

    return (0);
}