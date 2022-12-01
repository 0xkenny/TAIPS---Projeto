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
  char name[30]; // Nome
};

int generateId() { return rand() % 900000000 + 99999999; }

void gotoxy(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getCoords(char c) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    c = toupper(c);
    if(c == 'C') return columns;
    if(c == 'R') return rows;
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}