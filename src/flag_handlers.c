// Copyright 2023 OsipyanG
#include "./flag_handlers.h"

void b_flag_handle(int *line_number) { printf("%6d\t", ++(*line_number)); }

void e_flag_handle() { putchar('$'); }

void t_flag_handle() {
  putchar('^');
  putchar('I');
}

void v_flag_handle(char *ch, bool *print) {
  if (!isascii(*ch) && !isprint(*ch)) {
    putchar('M');
    putchar('-');
    *ch = toascii(*ch);
  }
  if (iscntrl(*ch)) {
    putchar('^');
    putchar(*ch == 127 ? '?' : *ch + 64);
    *print = true;
  }
}
