#ifndef BOARD_H
#define BOARD_H

#include "defs.h"
#include "exits.h"
#include "options.h"

typedef struct board_s {
  side_t side_to_move;
  castle_t castle_rights;
  U64 pieces[2][6];
  square_t ep_square;
  int half_move_clock;
  int full_move_num;
} board_t;


void empty_board(board_t *);
exit_t validate_board(board_t *, val_opt_t);
char *decode_castling_rights(int);

#endif
