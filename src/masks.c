#include "masks.h"
#include "bitboard.h"

const U64 a_file = 72340172838076673ULL;
const U64 h_file = 9259542123273814144ULL;

U64 pawn_attack_mask(square, side) {
  U64 bb = 0ULL;

  if(square < 8 || square > 55)
    return bb;

  if(side == WHITE) {
    if((1ULL << square) & a_file) {
      set_bit((square - 7), bb);
    } else if((1ULL << square) & h_file) {
      set_bit((square - 9), bb);
    } else {
      set_bit((square - 7), bb);
      set_bit((square - 9), bb);
    }
  } else {
    if((1ULL << square) & a_file) {
      set_bit((square + 9), bb);
    } else if((1ULL << square) & h_file) {
      set_bit((square + 7), bb);
    } else {
      set_bit((square + 9), bb);
      set_bit((square + 7), bb);
    }
  }

  return bb;
}
