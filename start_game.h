#pragma once
#include "game.h"

player_t init_player(int is_white);
piece generate_unit(piece_t id, int row, int column, int is_white);
player_t generate_player(int is_white, int row);
game start_game();