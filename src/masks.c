#include "masks.h"
#include "bitboard.h"

const U64 A_FILE = 72340172838076673ULL;
const U64 H_FILE = 9259542123273814144ULL;
const U64 RANK_2 = 71776119061217280ULL;
const U64 RANK_7 = 65280ULL;
const U64 RANK_18 = 18374686479671623935ULL;

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

U64 pawn_motion_mask(square, side) {
  U64 bb = 0ULL;
  if(get_bit(square, RANK_18))
    return 0ULL;

  if(side == WHITE) {
    if(get_bit(square, RANK_2)) {
      set_bit((square - 8), bb);
      set_bit((square - 16), bb);
    } else {
      set_bit((square - 8), bb);
    }
  } else {
    if(get_bit(square, RANK_7)) {
      set_bit((square + 8), bb);
      set_bit((square + 16), bb);
    } else {
      set_bit((square + 8), bb);
    }
  }

  return bb;
}
