#include <stdbool.h>
#include <stdio.h>

struct aeroplane {
  int id;               // id unico
  int capacity;         // (mínimo de 2 e máximo de 4)
  bool status;          // True = Pronto | False = Autorização
  char passengerList;   // TODO: Array?
  char local[30];       // Local onde está
  char destination[30]; // Destino
  // int history[5]; o historico dos ultimos voos sera um array ent n sei o que
  // colocar
  int flightCount;
};

int main(void) {
  printf("Hello World\n");

  return 0;
}

// Ideias de como comecar i guess
