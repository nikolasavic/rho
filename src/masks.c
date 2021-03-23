#include "masks.h"
#include "bitboard.h"

const U64 FILE_A = 72340172838076673ULL;
const U64 FILE_AB = 217020518514230019ULL;
const U64 FILE_GH = 13889313184910721216ULL;
const U64 FILE_H = 9259542123273814144ULL;
const U64 RANK_12 = 18446462598732840960ULL;
const U64 RANK_1 = 18374686479671623680ULL;
const U64 RANK_2 = 71776119061217280ULL;
const U64 RANK_7 = 65280ULL;
const U64 RANK_8 = 255ULL;
const U64 RANK_18 = 18374686479671623935ULL;
const U64 RANK_78 = 65535ULL;

U64 pawn_attack_mask(int square, int side) {
  U64 bb = 0ULL;

  if(square < 8 || square > 55)
    return bb;

  if(side == WHITE) {
    if(get_bit(square, FILE_A)) {
      set_bit((square - 7), bb);
    } else if(get_bit(square, FILE_H)) {
      set_bit((square - 9), bb);
    } else {
      set_bit((square - 7), bb);
      set_bit((square - 9), bb);
    }
  } else {
    if(get_bit(square, FILE_A)) {
      set_bit((square + 9), bb);
    } else if(get_bit(square, FILE_H)) {
      set_bit((square + 7), bb);
    } else {
      set_bit((square + 9), bb);
      set_bit((square + 7), bb);
    }
  }

  return bb;
}

U64 pawn_motion_mask(int square, int side) {
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

U64 king_attack_mask(int square) {
  U64 bb = 0ULL;
  if(!get_bit(square, RANK_8))
    set_bit((square - 8), bb);
  if(!get_bit(square, FILE_H) && !get_bit(square, RANK_8))
    set_bit((square - 7), bb);
  if(!get_bit(square, FILE_A) && !get_bit(square, RANK_8))
    set_bit((square - 9), bb);
  if(!get_bit(square, FILE_A))
    set_bit((square - 1), bb);
  if(!get_bit(square, FILE_H))
    set_bit((square + 1), bb);
  if(!get_bit(square, RANK_1) && !get_bit(square, FILE_A))
    set_bit((square + 7), bb);
  if(!get_bit(square, RANK_1))
    set_bit((square + 8), bb);
  if(!get_bit(square, RANK_1) && !get_bit(square, FILE_H))
    set_bit((square + 9), bb);

  return bb;
}

U64 knight_attack_mask(int square) {
  U64 bb = 0ULL;
  if(!get_bit(square, RANK_78) && !get_bit(square, FILE_H))
    set_bit((square - 15), bb);
  if(!get_bit(square, FILE_A) && !get_bit(square, RANK_78))
    set_bit((square - 17), bb);
  if(!get_bit(square, RANK_8) && !get_bit(square, FILE_GH))
    set_bit((square - 6), bb);
  if(!get_bit(square, FILE_AB) && !get_bit(square, RANK_8))
    set_bit((square - 10), bb);
  if(!get_bit(square, RANK_1) && !get_bit(square, FILE_AB))
    set_bit((square + 6), bb);
  if(!get_bit(square, RANK_1) && !get_bit(square, FILE_GH))
    set_bit((square + 10), bb);
  if(!get_bit(square, RANK_12) && !get_bit(square, FILE_A))
    set_bit((square + 15), bb);
  if(!get_bit(square, RANK_12) && !get_bit(square, FILE_H))
    set_bit((square + 17), bb);

  return bb;
}

U64 bishop_attack_mask(int square, U64 block) {
  U64 bb = 0ULL;
  int target;

  target = square;
  while(!get_bit(target, FILE_H) && !get_bit(target, RANK_8)) {
    target -= 7;
    set_bit(target, bb);
  }

  target = square;
  while(!get_bit(target, FILE_A) && !get_bit(target, RANK_8)) {
    target -= 9;
    set_bit(target, bb);
  }

  target = square;
  while(!get_bit(target, FILE_H) && !get_bit(target, RANK_1)) {
    target += 9;
    set_bit(target, bb);
  }

  target = square;
  while(!get_bit(target, FILE_A) && !get_bit(target, RANK_1)) {
    target += 7;
    set_bit(target, bb);
  }

  return bb;
}

U64 rook_attack_mask(int square, U64 block) {
  U64 bb = 0ULL;
  int target;

  target = square;
  while(!get_bit(target, RANK_8)) {
    target -= 8;
    set_bit(target, bb);
  }

  target = square;
  while(!get_bit(target, RANK_1)) {
    target += 8;
    set_bit(target, bb);
  }

  target = square;
  while(!get_bit(target, FILE_H)) {
    target += 1;
    set_bit(target, bb);
  }

  target = square;
  while(!get_bit(target, FILE_A)) {
    target -= 1;
    set_bit(target, bb);
  }

  return bb;
}
