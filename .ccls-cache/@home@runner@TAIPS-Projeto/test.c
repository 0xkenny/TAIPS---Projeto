#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menu(char options[12][30]) {

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

    // Options List
    for(int i = 0; i < 12; i++) {
        gotoxy(5, 2 + i + 1);
        printf("%s", options[i]);
    }
}

void menuArrow(int position) {
    // Clear arrow
    for(int i = 0; i < 12; i++) {
        gotoxy(3, 2 + i + 1);
        printf(" ");
    }

    gotoxy(3, 2 + position);
    printf(">");
    gotoxy(0, 20);
}

int main() {
    int columns = getCoords('C'), rows = getCoords('R');
    int position = 1, keyPressed = 0, option = 0;

    char options[12][30] = { "Aeroplane Details", "Aeroplane Status", "Listar Aeronaves Autorizacao", "List Aeroplanes", "Add Aeroplane", "Edit Aeroplane", "Delete Aeroplane", "Authorize Fligth", "Cancel Fligth", "Save Aeroplanes", "Quit" };

    //gotoxy(columns / 2, rows / 2);

    hideCursor();
    menu(options);
    menuArrow(position);

    while(1) {
        keyPressed = getch();

        // Key Handler
        switch(keyPressed) {
            // Enter
            case 13:
                option = position;
                break;

            // Arrow Up
            case 72:
                if(position > 1) menuArrow(--position);
                break;

            // Arrow Down
            case 80:
                if(position < 11) menuArrow(++position);
                break;

            default:
                position = position;
                break;
        }

        // Menu option
        switch(option) {
            case 11:
                exit(0);
                break;
        }
    }
}
