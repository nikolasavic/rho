#include "masks.h"
#include "bitboard.h"

const U64 A_FILE = 72340172838076673ULL;
const U64 H_FILE = 9259542123273814144ULL;

U64 pawn_attack_mask(square, side) {
  U64 bb = 0ULL;

  if(square < 8 || square > 55)
    return bb;

  if(side == WHITE) {
    if(get_bit(square, A_FILE)) {
      set_bit((square - 7), bb);
    } else if(get_bit(square, H_FILE)) {
      set_bit((square - 9), bb);
    } else {
      set_bit((square - 7), bb);
      set_bit((square - 9), bb);
    }
  } else {
    if(get_bit(square, A_FILE)) {
      set_bit((square + 9), bb);
    } else if(get_bit(square, H_FILE)) {
      set_bit((square + 7), bb);
    } else {
      set_bit((square + 9), bb);
      set_bit((square + 7), bb);
    }
  }

  return bb;
}
