#include <stdio.h>


int main(int argc, char *argv[]) {
  int areas[] = { 10, 12, 15, 20, 30};
  char name[] = "Chugiya";
  char full_name[] = {
    'S', 'A', 'H', 'I', 'L', '\0'
  };
  printf("The size of int: %ld\n", sizeof(int));
  printf("the size of areas (int[]): %ld\n", sizeof(areas));
  printf("The number of eles: %ld\n", sizeof(areas)/sizeof(int));

  printf("Areas: 0-%d\n", areas[11]);
  printf("The size of char: %ld\n", sizeof(char));
  printf("The number of chars: %ld\n", sizeof(full_name)/sizeof(char));
  printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
  return 0;
}
