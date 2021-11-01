#ifndef MASKS_H
#define MASKS_H

#include "board.h"

U64 pawn_attack_mask(square_t, side_t);
U64 pawn_motion_mask(square_t, side_t);
U64 king_attack_mask(square_t);
U64 knight_attack_mask(square_t);
U64 bishop_attack_mask(square_t, U64);
U64 rook_attack_mask(square_t, U64);
U64 ray_north(square_t);
U64 ray_north_east(square_t);
U64 ray_east(square_t);
U64 ray_south_east(square_t);
U64 ray_south(square_t);
U64 ray_south_west(square_t);
U64 ray_west(square_t);
U64 ray_north_west(square_t);

#endif
