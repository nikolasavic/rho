#include <stdio.h>
#include "defs.h"
#include "bitboard.h"
#include "masks.h"

int main(void) {
  U64 bb = 0ULL;

  for(int rank = 1; rank <= 8; rank++) {
    for(int file = 1; file <= 8; file++) {
      int square = (file - 1) + (rank - 1) * 8;
      bb = rook_attack_mask(square);
      print_bitboard(bb);
    }
  }

  return 0;
}
