#ifndef INOUT_H
#define INOUT_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "data.h"
#include "option.h"

#define BUFSIZE 1024             // 読み込むデータファイルの1行の最大文字数
#define OPTION_INFO "Ver. 1.0.0" // バージョン情報

void get_registors();
void free_registors();
Data *getdata(Data *data);
Option *getoption(int argc, char *argv[], Option *option);
Data *multipledata(Data *data, Option *option);
void printout(int argc, char *argv[], Data *data, Option *option);

#endif