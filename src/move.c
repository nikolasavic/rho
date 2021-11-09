#include <stdio.h>
#include "move.h"
#include "board.h"
#include "exits.h"

exit_t validate_move(move_t * move, val_opt_t option) {
  if(move->origin < A1 || move->origin > H8) {
    if(option == VERBOSE) {
      printf("Error: invalid origin square: %d\n", move->origin);
    }
    return FAIL;
  }

  if(move->target < A1 || move->target > H8) {
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

  if(move->promotion < B || move->promotion > NULL_P) {
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
  int promotion_flag = move->promotion > 0 && move->promotion < 6;
  int capture_flag = move->capture ? 1 : 0;
  int aux_x_flag = 0;
  int aux_y_flag = 0;

  if(move->quiet_move) {
  } else {
    if(move->double_pawn) {
      aux_x_flag = 0;
      aux_y_flag = 1;
    } else if(move->kingside_castle) {
      aux_x_flag = 1;
    } else if(move->queenside_castle) {
      aux_x_flag = 1;
      aux_y_flag = 1;
    } else if(move->ep_capture) {
      capture_flag = 1;
      aux_x_flag = 0;
      aux_y_flag = 1;
    } else if(promotion_flag) {
      if(move->promotion == Q) {
        aux_x_flag = 1;
        aux_y_flag = 1;
      } else if(move->promotion == R) {
        aux_x_flag = 1;
        aux_y_flag = 0;
      } else if(move->promotion == N) {
        aux_x_flag = 0;
        aux_y_flag = 0;
      } else if(move->promotion == B) {
        aux_x_flag = 0;
        aux_y_flag = 1;
      }
    }
  }

  result |= promotion_flag << 3;
  result |= capture_flag << 2;
  result |= aux_x_flag << 1;
  result |= aux_y_flag;

  return result;
}

exit_t decode_move(move_t * move, U16 encoded) {
  if(!validate_move(move, SILENT)) {
    return FAIL;
  }
  // Decode flags
  int promotion_flag = encoded & 8 ? 1 : 0;
  int capture_flag = encoded & 4 ? 1 : 0;
  int aux_x_flag = encoded & 2 ? 1 : 0;
  int aux_y_flag = encoded & 1 ? 1 : 0;

  move->quiet_move =
    !promotion_flag & !capture_flag & !aux_x_flag & !aux_y_flag;

  move->double_pawn =
    !promotion_flag & !capture_flag & !aux_x_flag & aux_y_flag;

  move->capture = capture_flag;

  move->ep_capture =
    !promotion_flag & capture_flag & !aux_x_flag & aux_y_flag;

  move->kingside_castle =
    !promotion_flag & !capture_flag & aux_x_flag & !aux_y_flag;

  move->queenside_castle =
    !promotion_flag & !capture_flag & aux_x_flag & aux_y_flag;

  if(promotion_flag) {
    if(aux_x_flag && aux_y_flag) {
      move->promotion = Q;
    } else if(aux_x_flag && !aux_y_flag) {
      move->promotion = R;
    } else if(!aux_x_flag && aux_y_flag) {
      move->promotion = B;
    } else if(!aux_x_flag && !aux_y_flag) {
      move->promotion = N;
    }

  }
  // Decode squares
  encoded = encoded >> 4;
  int file_targ = encoded & 7;
  int rank_targ = (encoded >> 3) & 7;
  int file_orig = (encoded >> 6) & 7;
  int rank_orig = (encoded >> 9) & 7;
  move->origin = 8 * rank_orig + file_orig;
  move->target = 8 * rank_targ + file_targ;

  return SUCCESS;
}

void print_move(move_t * move) {
  printf("%s->%s prom:%d, capt:%d, quiet:%d double:%d, king:%d, queen:%d\n",
         square_name[move->origin], square_name[move->target],
         move->promotion, move->capture, move->quiet_move,
         move->double_pawn, move->kingside_castle, move->queenside_castle);

}
