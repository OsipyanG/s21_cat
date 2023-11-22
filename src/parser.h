// Copyright 2023 OsipyanG
#ifndef PARSER_H
#define PARSER_H

#include <ctype.h>
#include <err.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./flags.h"

enum ERRORS {
  PARSING_ERROR = 1,
  MALLOC_ERROR = 2,
};

int parse_parameters(int argc, char **argv, Flags *flags, char ***files);
int parse_flags(int argc, char **argv, Flags *flags);
int parse_filenames(int argc, char **argv, char **files);
void init_flags(Flags *flags);

#endif
