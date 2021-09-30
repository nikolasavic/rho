#ifndef BOARD_H
#define BOARD_H

#include "defs.h"

typedef struct board {
  int side_to_move;
  int castle_rights;
  U64 pieces[2][6];
} board_t;

board_t empty_board(void);

#endif
