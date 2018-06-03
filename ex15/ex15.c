#include <stdio.h>

int main(int argc, char *argv[]) {
  int ages[] = {10, 20, 30, 40};

  char *names[] = {"Ana", "Fbana", "Rbana", "Muana"};
  char *names1[] = {"Sambo", "Bambo"};
  char **directory[2] = {names, names1};
  char ***universe[] = {directory};
  printf("dir %s\n", directory[0][0]);
  printf("dir %s\n", directory[1][0]);
  printf("univ %s\n", universe[0][0][0]);
  int count = sizeof(ages) / sizeof(int);
  int i = 0;
  printf("%p\n", names[1]);
  printf("%p\n", &names[1][0]);
  for (i = 0; i < count; i++) {
    printf("%s -%p has %d years alive.\n", names[i], &names[i], ages[i]);
  }

  printf("---\n");

  int *curr_age = ages;
  char **curr_name = names;
  char ***another_name = &curr_name;


  //printf("curr_age: %p\n", curr_age);
  printf("names: %p\n", names);
  printf("curr_name: %p\n", curr_name);

  for (i=0; i < count; i++) {
  printf("%s is %d years old\n", *(*(another_name) + i), *(curr_age + 1));
  }
}
