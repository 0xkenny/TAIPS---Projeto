#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Window Size
struct SMALL_RECT {
  SHORT Left;
  SHORT Top;
  SHORT Right;
  SHORT Bottom;
};

typedef struct Aeroplanes {
  int id;               // Unique ID
  int capacity;         // (mínimo de 2 e máximo de 4)
  bool status;          // True = Pronto | False = Autorização
  int passengerList[4]; // TODO: Array?
  char local[30];       // Local onde está
  char destination[30]; // Destino
  // int history[5];    // O historico dos ultimos voos sera um array ent n sei
  // o que
  int flightCount; // Flight Count
} Aeroplane;

typedef struct Passengers {
  int nif;       // Unique ID
  char name[30]; // Name
} Passenger;

int generateId() {
  srand(time(NULL));
  return rand() % 900000000 + 99999999;
}

void adjustWindowSize() {
  struct SMALL_RECT window;

  HANDLE hStdout;
  COORD coord;
  BOOL ok;

  hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  coord.X = 120;
  coord.Y = 40;
  ok = SetConsoleScreenBufferSize(hStdout, coord);

  window.Left = 0;
  window.Top = 0;
  window.Right = coord.X - 1;
  window.Bottom = coord.Y - 1;

  SetConsoleWindowInfo(hStdout, ok, &window);
}

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
  if (c == 'C')
    return columns;
  if (c == 'R')
    return rows;
  return 0;
}

void hideCursor() {
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = FALSE;
  SetConsoleCursorInfo(consoleHandle, &info);
}

void menu(char title[35], char options[12][30]) {
  int columns = getCoords('C'), rows = getCoords('R');
  int longestOptionString = 0;

  // Top Menu Bar
  gotoxy(columns / 2 - 30, rows / 2 - 16);
  for (int i = 0; i < 60; i++) {
    if (i == 0) {
      printf("%c", 201);
    } else if (i == 59) {
      printf("%c", 187);
    } else {
      printf("%c", 205);
    }
  }

  // Left Menu Bar
  for (int i = 0; i < 18; i++) {
    gotoxy(columns / 2 - 30, rows / 2 + i - 15);
    printf("%c", 186);
  }

  // Right Menu Bar
  for (int i = 0; i < 18; i++) {
    gotoxy(columns / 2 + 29, rows / 2 + i - 15);
    printf("%c", 186);
  }

  // Down Menu Bar
  gotoxy(columns / 2 - 30, rows / 2 + 3);
  for (int i = 0; i < 60; i++) {
    if (i == 0) {
      printf("%c", 200);
    } else if (i == 59) {
      printf("%c", 188);
    } else {
      printf("%c", 205);
    }
  }

  // Title
  int rest = strlen(title) % 2;
  gotoxy(columns - 60 - (strlen(title) / 2) - rest, 6);
  printf("%s", title);

  // Options List
  // Get Longest Option
  for (int i = 0; i < 12; i++) {
    if (strlen(options[i]) > longestOptionString) {
      longestOptionString = strlen(options[i]);
    }
  }

  // Write Options
  for (int i = 0; i < 12; i++) {
    gotoxy(columns - 60 - longestOptionString / 2, 8 + i + 1);
    printf("%s", options[i]);
  }
}

void menuArrow(int position) {
  int columns = getCoords('C'), rows = getCoords('R');

  // Clear arrow
  for (int i = 0; i < 12; i++) {
    gotoxy(columns - 60 - 14 - 2, 8 + i);
    printf(" ");
  }

  // Write Arrow
  gotoxy(columns - 60 - 14 - 2, 8 + position);
  printf(">");
}
