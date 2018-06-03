#include <stdio.h>

int main(int argc, char *argv[]){

  int i = 0;
  char *states[] = {
    "Delhisederlkhuigggf", "Punjab", "Haryana", "harry"
  };
  printf("%ld\n", sizeof(states));
  // a char array pointer is 8 bytes
  printf("%ld\n", sizeof(char *));
  argv[1] = states[0];
  states[0] = argv[0];
  for (i=0; i < argc+1; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }


  for (i=0; i < 4; i ++) {
    printf("state: %s\n", states[i]);
  }
  printf("foo");

}
