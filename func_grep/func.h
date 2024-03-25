#ifndef HEADERFILE_H
#define HEADERFILE_H
#define _GNU_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PATTERNS 1024

typedef struct {
  bool e;
  bool i;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool o;
} Flags;

Flags parse_flags(int argc, char *argv[]);

void process_files(char* patterns[], Flags flags, char* file_names[], int file_count, int pattern_count);

int process_file(FILE *file, char *patterns[], int pattern_count, Flags flags, int total_matches, char *file_names, bool multi);

#endif