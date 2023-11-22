// Copyright 2023 OsipyanG
#include "./cat.h"

#include "./flag_handlers.h"
#include "./parser.h"

int main(int argc, char *argv[]) {
  char **files;
  int err;
  int line_number = 0;
  Flags flags;
  init_flags(&flags);

  err = parse_parameters(argc, argv, &flags, &files);
  if (err != EXIT_SUCCESS) {
    return err;
  }

  if (argc - optind == 0) {
    cat(stdin, flags, &line_number);
  }

  open_files(argc, files, flags);

  free(files);
  return EXIT_SUCCESS;
}

void cat(FILE *fp, Flags flags, int *line_number) {
  int skip, prev;
  char ch;
  bool print;
  //
  if (fp == stdin && feof(stdin))
    clearerr(stdin);

  skip = 0;

  for (prev = '\n'; (ch = getc(fp)) != EOF; prev = ch) {
    print = false;
    if (prev == '\n') {
      if (flags.s) {
        if (ch == '\n') {
          if (skip)
            continue;
          skip = 1;
        } else {
          skip = 0;
        }
      }
      if (flags.n && (!flags.b || ch != '\n')) {
        b_flag_handle(line_number);
      }
    }
    if (ch == '\n') {
      if (flags.e) {
        e_flag_handle();
      }
    } else if (ch == '\t') {
      if (flags.t) {
        t_flag_handle();
        print = true;
      }
    } else if (flags.v) {
      v_flag_handle(&ch, &print);
    }
    if (!print) {
      putchar(ch);
    }
  }
}

void open_files(int argc, char **files, Flags flags) {
  FILE *fp;
  int line_number = 0;
  int count_of_files = argc - optind;
  for (int i = 0; i < count_of_files; i++) {
    if (is_minus(files[i])) {
      cat(stdin, flags, &line_number);
    } else {
      fp = fopen(files[i], "r");
      if (!fp) {
        warn("%s", files[i]);
        continue;
      }
      cat(fp, flags, &line_number);
      fclose(fp);
    }
  }
}

bool is_minus(char *file) {
  char *minus = "-";
  if (strcmp(file, minus) == 0) {
    return true;
  }
  return false;
}
