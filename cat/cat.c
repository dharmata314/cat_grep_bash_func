#include "../func_cat/func.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Enter a file name and (optionally) flags\n");
  } else {
    Flags flags = parse_flags(argc, argv);
    cat_mimic(argc, argv, flags);
  }
}