#pragma once

typedef enum PieceType {
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN,
} piece_t;

typedef struct Piece
{
  int is_white;
  piece_t id;
  int row;
  int column;
} piece;

typedef struct Game
{
  piece *pieces;
} game;
