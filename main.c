#include <stdio.h>
#include <unistd.h>
#include "start_game.c"
#include "display_game.c"
#include "game.h"

int main() {
  printf("Welcome to cccc!\n");
  printf("Want to play some Chess?\n");
  char *board = start_game();
  while (1) {
    print_to_console(board);
    sleep(1);
  }
  return 0; 
}