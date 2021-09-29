#ifndef BOARD_H
#define BOARD_H

#include "defs.h"
#include "bitboard.h"

struct board {
  int side_to_move;
  int castle_rights;
  bitboard pieces[2][6];
};

#endif
