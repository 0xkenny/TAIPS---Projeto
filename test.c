#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;


    //gotoxy(columns / 2, rows / 2);



    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == 0 || i == 10 - 1 || j == 0 || j == 10 - 1) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }


    return 0;
}