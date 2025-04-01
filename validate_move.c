#include <stdio.h>
#include <ctype.h>

#define WHITE_PAWN_ROW 48
#define BLACK_PAWN_ROW 8
#define UNKNOWN_ROW_START 99
#define MAX_DISTANCE 8
#define KING_DISTANCE 1
#define CHECK_ROW 1
#define CHECK_COLUMN 8
#define CHECK_RIGHT_DIAG 9
#define CHECK_LEFT_DIAG 7


int find_row_start(int check) {
  if(check % 8 == 0) {
    return check;
  }
  for (int i = 1; i < 8; i++) {
    int checking = check - i;
    if(checking % 8 == 0) {
      return check - i;
    }
  }
  return 0;
}

int is_same_column(int start, int end) {
  if(start % 8 == end % 8) {
    return 1;
  }
  return 0;
}

int is_in_row(int check, int checkAgainst) {
  if(checkAgainst == UNKNOWN_ROW_START) {
    checkAgainst = find_row_start(check);
  }
  int difference = check - checkAgainst;
  if(difference < 0 || difference >= 8) {
    return 0;
  }
  return 1;
}

int is_in_column(int start, int column) {
  return start % 8 == column;
}

int check_direction(int start, int end, int player, char *board, int direction, int distance) {
  int step = (start < end) ? direction : -direction;
  int i = start + step;
  
  while (i != end && i < 64 && i >= 0 && distance > 0) {
    if (board[i] != '.') {
      return 0;
    }
    i += step;
    direction -= 1;
  }
  if (i != end) {
    return 0;
  }
  if (board[end] != '.') {
    if ((player && isupper(board[end])) || (!player && islower(board[end]))) {
      return 1;
    }
    return 0;
  }
  
  return 1;
}

int validate_pawn(char *board, int start, int end, int player) {
  int direction = player ? 1 : -1;
  if((!player && is_in_row(start, WHITE_PAWN_ROW)) || (player && is_in_row(start, BLACK_PAWN_ROW))) {
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

int validate_bishop(char *board, int start, int end, int player) {
  return check_direction(start, end, player, board, CHECK_LEFT_DIAG, MAX_DISTANCE) || 
    check_direction(start, end, player, board, CHECK_RIGHT_DIAG, MAX_DISTANCE);
}

int validate_rook(char *board, int start, int end, int player) {
  return check_direction(start, end, player, board, CHECK_ROW, MAX_DISTANCE) || 
    check_direction(start, end, player, board, CHECK_COLUMN, MAX_DISTANCE);
}

int validate_king(char *board, int start, int end, int player) {
  return check_direction(start, end, player, board, CHECK_ROW, KING_DISTANCE) || 
    check_direction(start, end, player, board, CHECK_COLUMN, KING_DISTANCE) ||
    check_direction(start, end, player, board, CHECK_LEFT_DIAG, KING_DISTANCE) ||
    check_direction(start, end, player, board, CHECK_RIGHT_DIAG, KING_DISTANCE);
}

int validate_queen(char *board, int start, int end, int player) {
  return check_direction(start, end, player, board, CHECK_ROW, MAX_DISTANCE) || 
    check_direction(start, end, player, board, CHECK_COLUMN, MAX_DISTANCE) ||
    check_direction(start, end, player, board, CHECK_LEFT_DIAG, MAX_DISTANCE) ||
    check_direction(start, end, player, board, CHECK_RIGHT_DIAG, MAX_DISTANCE);
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
      validate_bishop(board, start, end, player);
      break;
    case 'r':
      validate_rook(board, start, end, player);
      break;
    case 'q':
      validate_queen(board, start, end, player);
      break;
    case 'k':
      validate_king(board, start, end, player);
      break;
    default:
      return 0;
      break;
  }
}