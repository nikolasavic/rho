#ifndef MOVE_H
#define MOVE_H

#include <stdbool.h>
#include "move.h"
#include "board.h"
#include "exits.h"

typedef unsigned short int U16;

typedef struct move_s {
  square_t origin;
  square_t target;
  piece_t promotion;
  bool quiet_move;
  bool double_pawn;
  bool capture;
  bool ep_capture;
  bool kingside_castle;
  bool queenside_castle;
} move_t;

exit_t validate_move(move_t *, val_opt_t);
U16 encode_move(move_t *);
exit_t decode_move(move_t *, U16);

#endif
