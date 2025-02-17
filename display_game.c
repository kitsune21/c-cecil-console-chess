#include <stdio.h>
#include "game.h"

void print_to_console(char board[8][8]) {

  printf("\033[H\033[J");
  printf("\t");
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("%d\n\t", i + 1);
  }

  printf("A B C D E F G H\n");
}