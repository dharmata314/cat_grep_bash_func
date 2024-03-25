#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  bool nnb;
  bool end_line;
  bool all_lines;
  bool squeeze;
  bool tabs;
  bool non_print;
} Flags;

void cat_mimic(int argc, char* aegv[], Flags flags);
Flags parse_flags(int argc, char *argv[]);

#endif