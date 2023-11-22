// Copyright 2023 OsipyanG
#ifndef CAT_H
#define CAT_H

#include <ctype.h>
#include <err.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./flags.h"

void cat(FILE *fp, Flags flags, int *line_number);
void open_files(int argc, char **files, Flags flags);
bool is_minus(char *file);

#endif
