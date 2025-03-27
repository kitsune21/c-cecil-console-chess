#include <stdio.h>
#include "game.h"

void print_to_console(char *board) {

  printf("\033[H\033[J");
  int row_num = 8;

  for (int i = 0; i < 64; i++) {
    if(i % 8 == 0 || i == 0) {
      printf("\n %d ", row_num);
      row_num--;
    }
    printf(" %c", board[i]);
  }
  printf("\n    A B C D E F G H\n");
}