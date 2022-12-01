#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


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

void menu(char options[12][30]) {

    // Top
    for(int i = 0; i < 45; i++) {
        if(i == 0) {
            printf("%c", 201);
        } else if(i == 44) {
            printf("%c", 187);
        } else {
            printf("%c", 205);
        }
    }

    // Left
    for(int i = 0; i < 15; i++) {
        gotoxy(0, i + 1);
        printf("%c", 186);
    }

    // Right
    for(int i = 0; i < 15; i++) {
        gotoxy(44, i + 1);
        printf("%c", 186);
    }

    // Down
    for(int i = 0; i < 45; i++) {
        if(i == 0) {
            printf("\n");
            printf("%c", 200);
        } else if(i == 44) {
            printf("%c", 188);
        } else {
            printf("%c", 205);
        }
    }


    for(int i = 0; i < 12; i++) {
        gotoxy(5, 2 + i + 1);
        printf("%s", options[i]);
    }
}

void menuArrow(int position) {
    for(int i = 0; i < 12; i++) {
        gotoxy(3, 2 + i + 1);
        printf(" ");
    }

    gotoxy(3, 2 + position);
    printf(">");
}

int main() {
    int columns = getCoords('C');
    int rows = getCoords('R');
    int keyPressed = 0;
    int position = 1;
    int opc = 0;

    char options[12][30] = { "Aeroplane Details", "Aeroplane Status", "Listar Aeronaves Autorizacao", "List Aeroplanes", "Add Aeroplane", "Edit Aeroplane", "Delete Aeroplane", "Authorize Fligth", "Cancel Fligth", "Save Aeroplanes", "Quit" };

    //gotoxy(columns / 2, rows / 2);

    menu(options);
    menuArrow(position);

    if(getch() == 80 && position < 12) {
        position++;
        menuArrow(position);
    } else if(getch() == 72 > 1) {
        position--;
        menuArrow(position);
    } else {
        position = position;
    }

    gotoxy(20, 20);


    switch(opc) {
    case 0:
        break;

    case 1:
        return 0;
        break;
    }
}