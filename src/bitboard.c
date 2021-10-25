#include <stdio.h>
#include "bitboard.h"

void print_bitboard(U64 bitboard) {
  printf("\n");
  for(int rank = 7; rank >= 0; rank--) {
    printf("%d  ", rank + 1);
    for(int file = 0; file <= 7; file++) {
      int square = file + rank * 8;
      printf("%d ", get_bit(square, bitboard));
    }
    printf("\n");
  }
  printf("\n   a b c d e f g h\n");
  printf("U64: %llu\n\n", bitboard);
}

int pop_count(U64 bb) {
  int count;

  for(count = 0; bb; bb >>= 1) {
    count += bb & 1;
  }
  return count;
}

const int index64[64] = {
  0, 1, 48, 2, 57, 49, 28, 3,
  61, 58, 50, 42, 38, 29, 17, 4,
  62, 55, 59, 36, 53, 51, 43, 22,
  45, 39, 33, 30, 24, 18, 12, 5,
  63, 47, 56, 27, 60, 41, 37, 16,
  54, 35, 52, 21, 44, 32, 23, 11,
  46, 26, 40, 15, 34, 20, 31, 10,
  25, 14, 19, 9, 13, 8, 7, 6
};

int bitscan_fwd(U64 bb) {
  const U64 debruijn64 = 0x03f79d71b4cb0a89ULL;
  return index64[((bb & -bb) * debruijn64) >> 58];
}
