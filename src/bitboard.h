#ifndef BITBOARD_H
#define BITBOARD_H

#define set_bit(square, bitboard) (bitboard |= (1ULL << square))

#define get_bit(square, bitboard) ((bitboard & (1ULL << square)) ? 1 : 0)

#define pop_bit(square, bitboard) ((bitboard & (1ULL << square)) ? bitboard ^= (1ULL << square) : 0)

typedef unsigned long long U64;

typedef enum {
  NORTH, NO_EAST, EAST, SO_EAST, SOUTH, SO_WEST, WEST, NO_WEST
} dir_t;

extern U64 rays[8][64];

void print_bitboard(U64);
int pop_count(U64);
int bitscan_fwd(U64);
int bitscan_rev(U64);

#endif
