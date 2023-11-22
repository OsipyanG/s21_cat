// Copyright 2023 OsipyanG
#include "./parser.h"

int parse_parameters(int argc, char **argv, Flags *flags, char ***files) {
  int error;
  error = parse_flags(argc, argv, flags);
  if (error != EXIT_SUCCESS) {
    printf("usage: cat [-benstv] [file ...]");
    return PARSING_ERROR;
  }
  *files = (char **)malloc(sizeof(char *) * (argc - optind));
  if (*files == NULL) {
    return MALLOC_ERROR;
  }
  parse_filenames(argc, argv, *files);
  return EXIT_SUCCESS;
}

int parse_flags(int argc, char **argv, Flags *flags) {
  int c;
  while (true) {
    int option_index = 0;
    static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                           {"number", 0, 0, 'n'},
                                           {"squeeze-blank", 0, 0, 's'},
                                           {0, 0, 0, 0}};
    c = getopt_long(argc, argv, "beEnstTv", long_options, &option_index);
    if (c == -1)
      break;
    switch (c) {
    case 'b':
      flags->b = true;
      flags->n = true;
      break;
    case 'e':
      flags->e = true;
      flags->v = true;
      break;
    case 'E':
      flags->e = true;
      break;
    case 'n':
      flags->n = true;
      break;
    case 's':
      flags->s = true;
      break;
    case 't':
      flags->t = true;
      flags->v = true;
      break;
    case 'T':
      flags->t = true;
      break;
    case 'v':
      flags->v = true;
      break;
    case '?':
      return PARSING_ERROR;
    default: {
    };
    }
  }
  return EXIT_SUCCESS;
}

int parse_filenames(int argc, char **argv, char **files) {
  int file_index = 0;
  for (int i = optind; i < argc; i++) {
    files[file_index] = argv[i];
    file_index++;
  }
  return EXIT_SUCCESS;
}

void init_flags(Flags *flags) {
  flags->b = false;
  flags->e = false;
  flags->n = false;
  flags->s = false;
  flags->t = false;
  flags->v = false;
}
