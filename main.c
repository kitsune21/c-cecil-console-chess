#include <stdio.h>
#include <unistd.h>
#include "start_game.c"
#include "display_game.c"
#include "game.h"

int main() {
  printf("Welcome to c-chess!\n");
  printf("Want to play the game?\n");
  game my_game = start_game();
  while (1) {
    print_to_console(my_game);
    sleep(1); // Delay for 1 second
  }
  return 0; 
}