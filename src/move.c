#include <stdio.h>
#include "move.h"
#include "board.h"
#include "exits.h"

exit_t validate_move(move_t * move, val_opt_t option) {
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

  if(move->origin == move->target) {
    if(option == VERBOSE) {
      printf("Error: origin and target squares equal: %d\n", move->target);
    }
    return FAIL;
  }

  if(move->promotion < 1 || move->promotion > 6) {
    if(option == VERBOSE) {
      printf("Error: invalid promotion piece: %d\n", move->promotion);
    }
    return FAIL;
  }

  if(move->capture && (move->quiet_move || move->double_pawn ||
                       move->kingside_castle || move->queenside_castle)) {
    if(option == VERBOSE) {
      printf("Error: capture flag on a quiet move: %d\n", move->promotion);
    }
    return FAIL;
  }

  return SUCCESS;
}

U16 encode_move(move_t * move) {
  U16 result = 0;
  // Encode squares
  result |= square_to_rank[move->origin] << 13;
  result |= square_to_file[move->origin] << 10;
  result |= square_to_rank[move->target] << 7;
  result |= square_to_file[move->target] << 4;

  // Encode flags
  // WIP

  return result;
}

exit_t decode_move(move_t * move, U16 encoded) {
  if(!validate_move(move, SILENT)){
    return FAIL;
  }

  // Decode flags
  // WIP
  if((encoded & 15) == 0) {
    move->quiet_move = true;
  }

  // Decode squares
  encoded = encoded >> 4;
  int file_targ = encoded & 7;
  int rank_targ = (encoded >> 3) & 7;
  int file_orig = (encoded >> 6) & 7;
  int rank_orig = (encoded >> 9) & 7;
  move->origin = 8 * (7 - rank_orig) + file_orig;
  move->target = 8 * (7 - rank_targ) + file_targ;

  return SUCCESS;
}

void print_move(move_t * move) {
  printf("%s->%s prom:%d, capt:%d, quiet:%d double:%d, king:%d, queen:%d\n",
      square_name[move->origin], square_name[move->target],
      move->promotion, move->capture, move->quiet_move,
      move->double_pawn, move->kingside_castle, move->queenside_castle);

}
