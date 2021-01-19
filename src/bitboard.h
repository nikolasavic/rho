#ifndef BITBOARD_H
#define BITBOARD_H

#define set_bit(square, bitboard) (bitboard |= (1ULL << square))

#define get_bit(square, bitboard) ((bitboard & (1ULL << square)) ? 1 : 0)

#define pop_bit(square, bitboard) ((bitboard & (1ULL << square)) ? bitboard ^= (1ULL << square) : 0)

void print_bitboard(U64 bb);

int pop_count(U64 bb);

#endif
