#ifndef MASKS_H
#define MASKS_H

#include "board.h"

U64 pawn_attack_mask(int, int);
U64 pawn_motion_mask(int, int);
U64 king_attack_mask(int);
U64 knight_attack_mask(int);
U64 bishop_attack_mask(int, U64);
U64 rook_attack_mask(int, U64);

#endif
