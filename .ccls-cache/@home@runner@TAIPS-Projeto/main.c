#include "taips.h"
#include <stdio.h>
#include 

int main(void) {
  srand(time(NULL));

  printf("Hello World\n");
  struct aeroplane aero;

  aero.status = true;

  for (int i = 0; i < 30; i++) {
    printf("%d\n", generateId());
  }

  return 0;
}

// Ideias de como comecar i guess
