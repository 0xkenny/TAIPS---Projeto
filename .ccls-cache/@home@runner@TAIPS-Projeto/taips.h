#include <stdbool.h>
#include <stdlib.h>

struct aeroplane {
  int id;               // id unico
  int capacity;         // (mínimo de 2 e máximo de 4)
  bool status;          // True = Pronto | False = Autorização
  int passengerList[4]; // TODO: Array?
  char local[30];       // Local onde está
  char destination[30]; // Destino
  // int history[5]; o historico dos ultimos voos sera um array ent n sei o que
  int flightCount;
};

struct passenger {
  int nif;       // id unico
  char nome[30]; // Nome
};

int generateId() { return rand() % 900000000 + 99999999; }

void menu() { printf("asd"); }

