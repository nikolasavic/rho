#include <stdio.h>
#include "move.h"
#include "exits.h"

exit_t validate_move(move_t *move, val_opt_t option) {
  if(move->origin < 0 || move->origin > 63) {
    if(option == VERBOSE) {
      printf("Error: invalid origin square: %d\n", move->origin);
    }
    return FAIL;
  }

  if(move->target < 0 || move->target > 63) {
    if(option == VERBOSE) {
      printf("Error: invalid target square: %d\n", move->target);
    }
    return FAIL;
  }

  if(move->promotion < 1 || move->promotion > 6) {
    if(option == VERBOSE) {
      printf("Error: invalid promotion piece: %d\n", move->promotion);
    }
    return FAIL;
  }

  if(move->capture &&
      (move->quiet_move || move->double_pawn || move->kingside_castle || move-> queenside_castle)) {
    if(option == VERBOSE) {
      printf("Error: capture flag on a quiet move: %d\n", move->promotion);
    }
    return FAIL;
  }

  return SUCCESS;
}

U16 encode_move(move_t *move) {
  return 0;
}

exit_t decode_move(move_t *move, U16 encoded) {
  return FAIL;
}
