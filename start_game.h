#pragma once
#include "game.h"

char piece_char(piece_t my_piece);
void add_to_board(char board[8][8], char p, int row, int col);
char *start_game();