#include "func.h"

Flags parse_flags(int argc, char* argv[]) {
  struct option long_flags[] = {
      {"number-nonblank", no_argument, 0, 'b'},
      {"E", no_argument, 0, 'E'},
      {"e", no_argument, 0, 'e'},
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},
      {"T", no_argument, 0, 'T'},
      {"t", no_argument, 0, 't'},
      {"v", no_argument, 0, 'v'},
  };

  Flags flags = {false, false, false, false, false, false};

  int current_flag;

  while ((current_flag =
              getopt_long(argc, argv, "bevEnstT", long_flags, NULL)) != -1) {
    switch (current_flag) {
      case 'b':
        flags.nnb = true;
        break;

      case 'e':
        flags.end_line = true;
        flags.non_print = true;
        break;

      case 'v':
        flags.non_print = true;
        break;

      case 'E':
        flags.end_line = true;
        break;

      case 'n':
        flags.all_lines = true;
        break;

      case 's':
        flags.squeeze = true;
        break;

      case 't':
        flags.non_print = true;
        flags.tabs = true;
        break;

      case 'T':
        flags.tabs = true;
        break;
    }
  }
  return flags;
}

void cat_mimic(int argc, char* argv[], Flags flags) {
  int line;
  int new_line;
  int end_line;
  int content;

  for (int i = optind; i < argc; i++) {
    line = 1;
    new_line = 1;
    end_line = 0;

    FILE* file = fopen(argv[i], "r");

    if (file != NULL) {
      while ((content = fgetc(file)) != EOF) {
        if (flags.nnb && new_line && content != '\n') {
          printf("%6d\t", line);
          line++;
          new_line = 0;
        }

        if (flags.all_lines && new_line) {
          printf("%6d\t", line);
          line++;
          new_line = 0;
        }

        if (flags.end_line && content == '\n') {
          printf("$");
        }

        if (flags.squeeze) {
          if (content == '\n') {
            ++end_line;
            if (end_line > 2) {
              continue;
            }
          } else {
            end_line = 0;
          }
        }

        if (flags.tabs && content == '\t') {
          printf("^");
          content = 'I';
        }

        if (flags.non_print && content != '\n' && content != '\t') {
          if (content >= 0 && content <= 31) {
            printf("^");
            content += 64;
          } else if (content == 127) {
            printf("^");
            content -= 64;
          }
        }

        if (content == '\n') new_line = 1;
        printf("%c", content);
      }
    } else {
      printf("cat: %s: No such file or directory\n", argv[i]);
    }
    fclose(file);
  }
}