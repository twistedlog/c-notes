#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
  char sex;
};

struct Person *person_create(char *name, int age, int height, int weight, char sex){
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  //who->name = NULL;
  who->age = age;
  who->height = height;
  who->weight = weight;
  who->sex = sex;
  return who;
}

void person_destroy(struct Person *person) {
  assert(person != NULL);
  //free(person->name);
  free(person);
}

void person_print(struct Person *person) {
  assert(person != NULL);

  printf("Name: %s\n", person->name);
  printf("Age: %d\n", person->age);
  printf("Height: %d\n", person->height);
  printf("Weight: %d\n", person->weight);
  printf("Sex: %c\n", person->sex);
}

int main(int argc, char *argv[]) {
  struct Person *p1 = person_create("Sahil", 28, 150, 65, 'M');
  person_print(p1);
  printf("Sahil is at memory location: %p\n", p1);
  printf("Sahil's name is at memory location: %s\n", p1);
  p1->age +=1;
  // char ascii value is increased by 1
  p1->sex += 1;
  person_print(p1);
  //ex16(25431,0x7fffbcc6c3c0) malloc: *** error for object 0x101662fb0: pointer being freed was not allocated
  //p1->name = "chug";
  person_destroy(p1);
  return 0;
}
