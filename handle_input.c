#include "validate_move.c"

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
    return 1;
    break;
  case 'b':
    return 2;
    break;
  case 'c':
    return 3;
    break;
  case 'd':
    return 4;
    break;
  case 'e':
    return 5;
    break;
  case 'f':
    return 6;
    break;
  case 'g':
    return 7;
    break;
  case 'h':
    return 8;
    break;
  
  default:
    return 9;
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
    case 'N':
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
    case 'n':
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

int valid_square(char square, int player) {
  if(square == '.') {
    return 1;
  }
  if(valid_piece(square, !player)) {
    return 1;
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
  int player_piece_row = 8 - (input[1] - '0'); //The 8 - swaps from 0-7 to 1-8
  int selected_square_col = convert_col_to_int(input[2]);
  int selected_square_row = 8 - (input[3] - '0');
  int player_piece_index = convert_row_column_to_index(player_piece_row, player_piece_col) - 1;
  int selected_square_index = convert_row_column_to_index(selected_square_row, selected_square_col) - 1;

  if(valid_piece(board[player_piece_index], player)) {
    if(valid_square(board[selected_square_index], player)) {
      if(validate_move(board, player_piece_index, selected_square_index, player)) {
        return 1;
      }
      return 0;
    }
    return 0;
  }

  return 0;
}