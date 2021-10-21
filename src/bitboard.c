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
