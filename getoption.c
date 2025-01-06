#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inout.h"
#include "option.h"

Option *getoption(int argc, char *argv[], Option *option)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-k") == 0 && i + 1 < argc)
        {
            option->times = atof(argv[i + 1]);

            break;
        }
        else if (strcmp(argv[i], "--help") == 0)
        {
            fprintf(stderr, "このコードの使い方は以下の通りです.\n");
            fprintf(stderr, "%s -k x: 各ベクトル成分 を x 倍する.\n", argv[0]);
            fprintf(stderr, "%s --help: このヘルプを出力.\n", argv[0]);
            exit(0);
        }
        else
        {
            fprintf(stderr, "不明なオプションです.\n");
            exit(1);
        }
    }

    // バージョ・作成日ン情報を設定
    option->info = OPTION_INFO;

    return option;
}