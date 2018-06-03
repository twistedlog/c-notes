#include <stdio.h>

int main(int argc, char *argv[]){
  int age = 10;
  int height = 60;

  //printf("I am %d years old.\n", agedock);
  printf(NULL);
  printf("I am %d inches tall\n", height);

  /*
  if i only ommit height in above printf statement the memory address doesn't change
  but on placing the line above the previous printf it keeps changing why?? #TODO find more on this

  [sahil.chug:...te/learn-c-the-hard-way/ex3]$ ./ex3
  I am 10 years old.
  I am 6526208 inches tall
  [sahil.chug:...te/learn-c-the-hard-way/ex3]$ ./ex3
  I am 10 years old.
  I am 6526208 inches tall
  [sahil.chug:...te/learn-c-the-hard-way/ex3]$ ./ex3

  I am 10 years old.
  I am 6526208 inches tall
  [sahil.chug:...te/learn-c-the-hard-way/ex3]$ ./ex3
  I am 10 years old.
  I am 6526208 inches tall

  */

  // return is implied no need to explicitly return #TODO check this more
  return 0;
}
