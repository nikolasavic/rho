#ifndef BOARD_H
#define BOARD_H

#include "defs.h"

typedef struct board_s {
  side_t side_to_move;
  castle_t castle_rights;
  U64 pieces[2][6];
  square_t ep_square;
  int half_move_clock;
  int full_move_num;
} board_t;

void empty_board(board_t *);
int validate_board(board_t *);

#endif
