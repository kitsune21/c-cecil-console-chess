#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char piece_char(piece_t my_piece) {
  switch (my_piece) {
  case W_PAWN:
    return 'P';
  case B_PAWN:
    return 'p';
  case W_KNIGHT:
    return 'H';
  case B_KNIGHT:
    return 'h';
  case W_BISHOP:
    return 'B';
  case B_BISHOP:
    return 'b';
  case W_ROOK:
    return 'R';
  case B_ROOK:
    return 'r';
  case W_QUEEN:
    return 'Q';
  case B_QUEEN:
    return 'q';
  case W_KING:
    return 'K';
  case B_KING:
    return 'k';
  default:
    return '0';
  }
}

void add_to_board(char board[8][8], char p, int row, int col) {
  board[row][col] = p;
}

char (*start_game())[8] {
  char (*board)[8] = malloc(sizeof(char[8][8]));
  if (board == NULL) {
    perror("Failed to allocate memory for the board");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = '.';
    }
  }

  for (int i = 0; i < 8; i++) {
    add_to_board(board, piece_char(W_PAWN), 1, i);
  }

  add_to_board(board, piece_char(W_ROOK),   0, 0);
  add_to_board(board, piece_char(W_KNIGHT), 0, 1);
  add_to_board(board, piece_char(W_BISHOP), 0, 2);
  add_to_board(board, piece_char(W_QUEEN),  0, 3);
  add_to_board(board, piece_char(W_KING),   0, 4);
  add_to_board(board, piece_char(W_BISHOP), 0, 5);
  add_to_board(board, piece_char(W_KNIGHT), 0, 6);
  add_to_board(board, piece_char(W_ROOK),   0, 7);

  for (int i = 0; i < 8; i++) {
    add_to_board(board, piece_char(B_PAWN), 6, i);
  }

  add_to_board(board, piece_char(B_ROOK),   7, 0);
  add_to_board(board, piece_char(B_KNIGHT), 7, 1);
  add_to_board(board, piece_char(B_BISHOP), 7, 2);
  add_to_board(board, piece_char(B_QUEEN),  7, 3);
  add_to_board(board, piece_char(B_KING),   7, 4);
  add_to_board(board, piece_char(B_BISHOP), 7, 5);
  add_to_board(board, piece_char(B_KNIGHT), 7, 6);
  add_to_board(board, piece_char(B_ROOK),   7, 7);

  return board;
}