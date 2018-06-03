#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
  int numbers[4] = {1};
  char *name = "aaa";

  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  printf("name: %c %c %c %c\n", name[0], name[1], name[2], name[3]);

  printf("name: %s\n", name);

  numbers[0] = 1;
  numbers[1] = 2;
  // prints ascii
  numbers[2] = 'f';
  numbers[3] = 4;

  // https://stackoverflow.com/questions/1011455/is-it-possible-to-modify-a-string-of-char-in-c
  char *a = malloc(4);
  strcpy(a, name);
  a[0] = 'S';
  a[1] = 'G';
  a[2] = 'H';
  // always terminate a string with \0
  a[3] = '\0';

  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

  printf("name: %c %c %c %c\n", a[0], a[1], a[2], a[3]);

  printf("name: %s\n", a);
  free(a);
  char *another = "Chug";

  printf("another: %s\n", another);
  printf("another: %c %c %c %c\n", another[0], another[1], another[2], another[3]);
  memcpy(&numbers[0], name, strlen(name));
  printf("numbers -0 : %d", numbers[0]);
  return 0;
}
