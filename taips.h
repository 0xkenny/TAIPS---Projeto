#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

typedef struct Aeroplanes {
    int id;               // Unique ID
    int capacity;         // (mínimo de 2 e máximo de 4)
    bool status;          // True = Pronto | False = Autorização
    int passengerList[4]; // TODO: Array?
    char local[30];       // Local onde está
    char destination[30]; // Destino
    // int history[5];    // O historico dos ultimos voos sera um array ent n sei o que
    int flightCount;      // Flight Count
} Aeroplane;

typedef struct Passengers {
    int nif;              // Unique ID
    char name[30];        // Name
} Passenger;

int generateId() {
    return rand() % 900000000 + 99999999;
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
    if(c == 'C') return columns;
    if(c == 'R') return rows;
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

    // Top Menu Bar
    for(int i = 0; i < 45; i++) {
        if(i == 0) {
            printf("%c", 201);
        } else if(i == 44) {
            printf("%c", 187);
        } else {
            printf("%c", 205);
        }
    }

    // Left Menu Bar
    for(int i = 0; i < 15; i++) {
        gotoxy(0, i + 1);
        printf("%c", 186);
    }

    // Right Menu Bar
    for(int i = 0; i < 15; i++) {
        gotoxy(44, i + 1);
        printf("%c", 186);
    }

    // Down Menu Bar
    for(int i = 0; i < 45; i++) {
        if(i == 0) {
            printf("\n%c", 200);
        } else if(i == 44) {
            printf("%c", 188);
        } else {
            printf("%c", 205);
        }
    }

    int rest = strlen(title) % 2;

    // Title
    gotoxy(22 - (strlen(title) / 2) - rest, 2);
    printf("%s", title);

    // Options List
    for(int i = 0; i < 12; i++) {
        gotoxy(5, 3 + i + 1);
        printf("%s", options[i]);
    }
}

void menuArrow(int position) {
    // Clear arrow
    for(int i = 0; i < 12; i++) {
        gotoxy(3, 3 + i + 1);
        printf(" ");
    }

    gotoxy(3, 3 + position);
    printf(">");
    gotoxy(0, 20);
}
