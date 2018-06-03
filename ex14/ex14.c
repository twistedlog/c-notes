#include <stdio.h>
#include <string.h>
#include <ctype.h>

// forward decalrations
int can_print_it(char ch);
void print_letters(char argv[], int len);

void print_arguments(int argc, char *argv[]) {
  int i = 0;
  for (i=0; i<argc; i++) {
    // strlen isnt actually safe
    print_letters(argv[i], strlen(argv[i]));
  }
}

void print_letters(char argv[], int len) {
  int i = 0;
  for (i=0; i < len; i++) {
    char ch = argv[i];
    if (isalpha((int)ch) || isblank((int)ch)) {
      printf("'%c' == %d\n", ch, ch);
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  print_arguments(argc+1, argv);
  return 0;
}
