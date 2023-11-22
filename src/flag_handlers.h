// Copyright 2023 OsipyanG
#ifndef FLAG_HANDLERS_H
#define FLAG_HANDLERS_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void b_flag_handle(int *line_number);
void e_flag_handle();
void t_flag_handle();
void v_flag_handle(char *ch, bool *print);

#endif // FLAG_HANDLERS_H
