#include <stdio.h>
#include "bitboard.h"

void print_bitboard(U64 bitboard) {
  printf("\n");
  for(int rank = 1; rank <= 8; rank++) {
    printf("%d  ", 9 - rank);
    for(int file = 1; file <= 8; file++) {
      int square = (file - 1) + (rank - 1) * 8;
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
