#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include "start_game.c"
#include "display_game.c"
#include "game.h"
#include "handle_input.c"

int take_turn(char *board, int player) {
  print_to_console(board);
  return handle_input(board, get_user_input(player), player);
}

int main() {
  char *board = start_game();
  int player = 0;
  while(1) {
    if(take_turn(board, player)) {
      player = player ? 0 : 1;
    }
  }
  return 0; 
}