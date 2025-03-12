#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include "start_game.c"
#include "display_game.c"
#include "game.h"

char *get_user_input() {
  char* input = malloc(sizeof(char) * 4);
  printf("Input your move: ");
  scanf("%s", input);
  return input;
}

int convert_col_to_int(char col) {
  char lowered_col = tolower(col);
  switch (lowered_col)
  {
  case 'a':
    return 0;
    break;
  case 'b':
    return 1;
    break;
  case 'c':
    return 2;
    break;
  case 'd':
    return 3;
    break;
  case 'e':
    return 4;
    break;
  case 'f':
    return 5;
    break;
  case 'g':
    return 6;
    break;
  case 'h':
    return 7;
    break;
  
  default:
    return 8;
    break;
  }
}

int valid_piece(char piece, int player) {
  if(!player) {
    switch (piece) {
    case 'P':
      return 1;
      break;
    case 'R':
      return 1;
      break;
    case 'H':
      return 1;
      break;
    case 'B':
      return 1;
      break;
    case 'Q':
      return 1;
      break;
    case 'K':
      return 1;
      break;
    
    default:
      return 0;
      break;
    }
  }
  switch (piece) {
    case 'p':
      return 1;
      break;
    case 'r':
      return 1;
      break;
    case 'h':
      return 1;
      break;
    case 'b':
      return 1;
      break;
    case 'q':
      return 1;
      break;
    case 'k':
      return 1;
      break;
    
    default:
      return 0;
      break;
  }
  return 0;
}

int handle_input(char *board, char *input, int player) {
  //convert the input to the two indexes
  //->make it all lowercase
  //->split it into player piece and selected square
  //check that the player piece is valid
  //->Is a piece of the correct color
  //check that the selected square is valid
  //->Is not a piece of the same color as the player
  //move the piece to the selected square
  int player_piece = 0;
  int selected_square = 0;
  
  int player_piece_col = convert_col_to_int(input[0]);
  int player_piece_row = input[1] - '0';
  int selected_square_col = convert_col_to_int(input[2]);
  int selected_square_row = input[3] - '0';
  int player_piece_index = convert_row_column_to_index(player_piece_row, player_piece_col) - 1;
  int selected_square_index = convert_row_column_to_index(selected_square_row, selected_square_col) - 1;

  if(valid_piece(board[player_piece_index], player)) {
    return 1;
  }

  return 0;
}

int main() {
  char *board = start_game();
  print_to_console(board);
  int valid = handle_input(board, get_user_input(), 1);
  if(valid) {
    printf("\nTesting");
  } else {
    printf("\nnot");
  }
  return 0; 
}