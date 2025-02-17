#include <stdio.h>
#include <stdlib.h>
#include "game.h"

piece generate_unit(piece_t id, int row, int column, int is_white) {
  piece my_unit;
  my_unit.is_white = is_white;
  my_unit.id = id;
  my_unit.row = row;
  my_unit.column = column;
  return my_unit;
}

void generate_pieces(game the_game, int is_white, int row, int i) {
  for(int j = 0; j < 8; j++) {
    piece pawn = generate_unit(PAWN, row, j, is_white);
    the_game.pieces[i] = pawn;
    i++;
  }
  if (is_white) {
    row = 0;
  } else {
    row = 7;
  }
  piece knight_1 = generate_unit(KNIGHT, row, 1, is_white);
  the_game.pieces[i] = knight_1;
  i++;
  piece knight_2 = generate_unit(KNIGHT, row, 6, is_white);
  the_game.pieces[i] = knight_2;
  i++;
  piece bishop_1 = generate_unit(BISHOP, row, 2, is_white);
  the_game.pieces[i] = bishop_1;
  i++;
  piece bishop_2 = generate_unit(BISHOP, row, 5, is_white);
  the_game.pieces[i] = bishop_2;
  i++;
  piece rook_1 = generate_unit(ROOK, row, 0, is_white);
  the_game.pieces[i] = rook_1;
  i++;
  piece rook_2 = generate_unit(ROOK, row, 7, is_white);
  the_game.pieces[i] = rook_2;
  i++;
  piece king = generate_unit(KING, row, 4, is_white);
  the_game.pieces[i] = king;
  i++;
  piece queen = generate_unit(QUEEN, row, 3, is_white);
  the_game.pieces[i] = queen;
}

game start_game() {
  game my_game;
  my_game.pieces = malloc(sizeof(piece) * 32);
  generate_pieces(my_game, 1, 1, 0);
  generate_pieces(my_game, 0, 6, 16);
  return my_game;
}