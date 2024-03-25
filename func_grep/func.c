#include "func.h"

void process_files(char *patterns[], Flags flags, char *file_names[],
                   int file_count, int pattern_count) {
  int total_matches = 0;
  bool multi = false;

  for (int i = 0; i < file_count; i++) {
    FILE *file = fopen(file_names[i], "r");

    if (file == NULL) {
      if (flags.s) {
        continue;
      }
      perror("grep: ");
      continue;
    }

    if (file_count > 1) multi = true;

    total_matches = process_file(file, patterns, pattern_count, flags,
                                 total_matches, file_names[i], multi);

    fclose(file);
  }

  if (flags.l && total_matches > 0) {
    for (int i = 0; i < file_count; i++) {
      printf("%s\n", file_names[i]);
    }
  }
}

int process_file(FILE *file, char *patterns[], int pattern_count, Flags flags,
                 int total_matches, char *file_names, bool multi) {
  char line[MAX_LINE_LENGTH];
  int line_number = 0;
  int matches_in_file = 0;

  while (fgets(line, sizeof(line), file) != NULL) {
    line_number++;

    int match_found = 0;

    for (int i = 0; i < pattern_count; i++) {
      char *match;
      if (flags.i) {
        match = strcasestr(line, patterns[i]);
      } else {
        match = strstr(line, patterns[i]);
      }

      if ((match != NULL && !flags.v) || (match == NULL && flags.v)) {
        match_found = 1;
        break;
      }
    }

    if (match_found) {
      matches_in_file++;

      if (flags.l) {
        total_matches++;
        break;
      }

      if (flags.c) {
        continue;
      }

      if (flags.n) {
        if (multi && !flags.h) printf("%s:", file_names);
        printf("%d:", line_number);
        if (strchr(line, '\n'))
          printf("%s", line);
        else
          printf("%s\n", line);
      }

      else {
        if (multi && !flags.h) {
          printf("%s:", file_names);
        }

        if (flags.o) {
          for (int i = 0; i < pattern_count; i++) {
            char *match = line;
            while ((match = strstr(match, patterns[i])) != NULL) {
              int match_length = strlen(patterns[i]);
              printf("%.*s\n", match_length, match);
              match += match_length;
            }
          }
        }

        else {
          if (strchr(line, '\n'))
            printf("%s", line);
          else
            printf("%s\n", line);
        }
      }
    }
  }

  if (flags.c) {
    if (multi && !flags.h) printf("%s:", file_names);
    printf("%d\n", matches_in_file);
  }

  return total_matches;
}