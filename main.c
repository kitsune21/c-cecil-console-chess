#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include "start_game.c"
#include "display_game.c"
#include "game.h"
#include "handle_input.c"

int main() {
  char *board = start_game();
  print_to_console(board);
  int valid = handle_input(board, get_user_input(), 0);
  if(valid) {
    printf("\nTesting");
  } else {
    printf("\nnot");
  }
  return 0; 
}