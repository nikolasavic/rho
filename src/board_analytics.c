#include <stdbool.h>
#include "board_analytics.h"
#include "bitboard.h"
#include "masks.h"

bool is_square_attacked(board_t* board, square_t square, side_t side) {
  if(board->pieces[!side][N] &&
     (board->pieces[!side][N] & knight_moves[square]))
    return true;

  if(board->pieces[!side][Q] &&
     (board->
      pieces[!side][Q] & queen_attack_mask(square, board->occupancy[BOTH])))
    return true;

  return false;
}
