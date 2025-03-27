#include <stdio.h>
#include <ctype.h>

int pawn_row_start(int player) {
  if(!player) {
    return 48;
  }
  return 8;
}

int pawn_row_end(int player) {
  if(!player) {
    return 55;
  }
  return 15;
}

int is_in_column(int start, int column) {
  return start % 8 == column;
}

int validate_pawn(char *board, int start, int end, int player) {
  int direction = player ? 1 : -1;
  if(start >= pawn_row_start(player) && start <= pawn_row_end(player)) {
    if(board[start + (8 * direction)] == '.') {
      if(end == start + (16 * direction)) {
        return 1;
      }
    }
  }
  if(end == start + (8 * direction)) {
    return 1;
  }
  if(!player && islower(board[end])) {
    if(end == start + (9 * direction) && !is_in_column(start, 0)) {
      return 1;
    }
    if(end == start + (7 * direction) && !is_in_column(start, 7)) {
      return 1;
    }
  }
  if(player && isupper(board[end])) {
    if(end == start + (9 * direction) && !is_in_column(start, 7)) {
      return 1;
    }
    if(end == start + (7 * direction) && !is_in_column(start, 0)) {
      return 1;
    }
  }
  return 0;
}

int validate_knight(char *board, int start, int end) {
  //check -17, -15, -10, -6 and reverse
  return 1;
}

int validate_bishop(char *board, int start, int end) {
  //check -7, -9
  return 1;
}

int validate_rook(char *board, int start, int end) {
  //check -8 * rows, -(1-8)
  //check if start and end are in the same row or same column
  return 1;
}

int validate_king(char *board, int start, int end) {
  //check -1, -8, -9, -7
  return 1;
}

int validate_queen(char *board, int start, int end) {
  //everything lol
  return 1;
}

int validate_move(char *board, int start, int end, int player) {
  char piece = tolower(board[start]);
  
  switch (piece) {
    case 'p':
      validate_pawn(board, start, end, player);
      break;
    case 'n':
      validate_knight(board, start, end);
      break;
    case 'b':
      validate_bishop(board, start, end);
      break;
    case 'r':
      validate_rook(board, start, end);
      break;
    case 'q':
      validate_queen(board, start, end);
      break;
    case 'k':
      validate_king(board, start, end);
      break;
    default:
      return 0;
      break;
  }
}