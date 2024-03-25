#include "../func_grep/func.h"

int main(int argc, char* argv[]) {
  int current_flag;
  char* patterns[MAX_PATTERNS];
  int pattern_count = 0;

  Flags flags = {false, false, false, false, false, false, false, false, false};

  while ((current_flag = getopt(argc, argv, "e:ivclnhso")) != -1) {
    switch (current_flag) {
      case 'e':
        if (pattern_count < MAX_PATTERNS) {
          patterns[pattern_count++] = optarg;
        }
        break;

      case 'i':
        flags.i = true;
        break;

      case 'v':
        flags.v = true;
        break;

      case 'c':
        flags.c = true;
        break;

      case 'l':
        flags.l = true;
        break;

      case 'n':
        flags.n = true;
        break;

      case 'h':
        flags.h = true;
        break;

      case 's':
        flags.s = true;
        break;

      case 'o':
        flags.o = true;
        break;
    }
  }

  if (pattern_count == 0 && optind < argc) {
    patterns[pattern_count++] = argv[optind++];
  }

  process_files(patterns, flags, &argv[optind], argc - optind, pattern_count);
}
