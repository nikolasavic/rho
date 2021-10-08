#ifndef MASKS_H
#define MASKS_H

#include "board.h"

U64 pawn_attack_mask(int square, int side);
U64 pawn_motion_mask(int square, int side);
U64 king_attack_mask(int square);
U64 knight_attack_mask(int square);
U64 bishop_attack_mask(int square, U64 block);
U64 rook_attack_mask(int square, U64 block);

#endif
