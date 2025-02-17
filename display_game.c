#include <stdio.h>
#include "game.h"

char piece_name(piece my_piece) {
  switch (my_piece.id)
  {
  case PAWN:
    if(my_piece.is_white) {
      return 'P';
    }
    return 'p';
  case KNIGHT:
    if(my_piece.is_white) {
      return 'H';
    }
    return 'h';
  case ROOK:
    if(my_piece.is_white) {
      return 'R';
    }
    return 'r';
  case BISHOP: 
    if(my_piece.is_white) {
      return 'B';
    }
    return 'b';
  case KING:
    if(my_piece.is_white) {
      return 'K';
    }
    return 'k';
  case QUEEN:
    if(my_piece.is_white) {
      return 'Q';
    }
    return 'q';
  default:
    return '0';
  }
}

void print_to_console(game my_game) {
  char board[8][8] = {0};

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = '.';
    }
  }

  for (int i = 0; i < 32; i++) {
    piece p = my_game.pieces[i];
    board[p.row][p.column] = piece_name(p);
  }

  printf("\033[H\033[J");

  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("%d\n", 8 - i);
  }

  printf("A B C D E F G H\n");
}