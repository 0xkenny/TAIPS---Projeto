#include "taips.h"

int main() {
  int columns = getCoords('C'), rows = getCoords('R');
  int position = 1, keyPressed = 0, option = 0;

  char options[12][30] = {"Aeroplane Details",
                          "Aeroplane Status",
                          "Listar Aeronaves Autorizacao",
                          "List Aeroplanes",
                          "Add Aeroplane",
                          "Edit Aeroplane",
                          "Delete Aeroplane",
                          "Authorize Fligth",
                          "Cancel Fligth",
                          "Save Aeroplanes",
                          "Quit"};

  // gotoxy(columns / 2, rows / 2);

  hideCursor();
  menu("TAIPS", options);
  menuArrow(position);

  while (1) {
    keyPressed = getch();

    // Key Handler
    switch (keyPressed) {
    // Enter
    case 13:
      option = position;
      break;

    // Arrow Up
    case 72:
      if (position > 1)
        menuArrow(--position);
      break;

    // Arrow Down
    case 80:
      if (position < 11)
        menuArrow(++position);
      break;

    default:
      position = position;
      break;
    }

    // Menu option
    switch (option) {
    case 11:
      exit(0);
      break;

    default:
      srand(time(NULL));

      Aeroplane aero;

      aero.id = generateId();
      aero.capacity = 2;

      /*printf("Id: %d\n", aero.id);
      printf("Capacity: %d\n", aero.capacity);*/

      break;
    }
  }
}
