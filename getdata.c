#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "inout.h"

Data *getdata(Data *data)
{
    int dim_num = 0, data_num = 0;
    char buf[BUFSIZE];

    // ファイルを開く
    FILE *fp = fopen("sample.dat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "ファイルを開くことができませんでした.\n");
        exit(1);
    }

    // データの行数と次元数を先に確定させる
    while (fgets(buf, BUFSIZE, fp) != NULL)
    {
        // コメント行はそのまま出力
        if ((buf[0] == '/' && buf[1] == '/') || buf[0] == '#')
        {
            printf("%s", buf);
        }
        else
        {
            char *ptr = buf;
            int count = 0;
            while (*ptr)
            {
                while (*ptr && isspace(*ptr))
                {
                    ptr++;
                }

                if (*ptr && !isspace((unsigned char)*ptr))
                {
                    strtod(ptr, &ptr);
                    count++;
                }
            }

            if (dim_num == 0)
            {
                dim_num = count;
            }

            // ベクトルの次元が一致しない場合
            else if (dim_num != count)
            {
                fprintf(stderr, "データの次元が一致しません.\n");
                exit(1);
            }

            data_num++;
        }
    }

    // メモリ確保
    data = malloc(sizeof(Data));
    data->dim = dim_num;
    data->num = data_num;
    data->v = malloc(sizeof(double *) * data_num);
    for (int i = 0; i < data_num; i++)
    {
        data->v[i] = malloc(sizeof(double) * dim_num);
    }

    // ファイルを再度開いてデータを読み込む
    rewind(fp);
    int index = 0;
    while (fgets(buf, BUFSIZE, fp) != NULL)
    {
        if ((buf[0] != '/' || buf[1] != '/') && buf[0] != '#')
        {
            char *ptr = buf;
            int count = 0;

            while (*ptr)
            {
                while (*ptr && isspace(*ptr))
                {
                    ptr++;
                }

                // データを格納
                if (*ptr && !isspace((unsigned char)*ptr))
                {
                    double value = strtod(ptr, &ptr);
                    data->v[index][count++] = value;
                }
            }
            index++;
        }
    }

    // ファイルを閉じる
    fclose(fp);

    return data;
}