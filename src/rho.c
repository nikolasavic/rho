#include <stdio.h>
#include "defs.h"
#include "bitboard.h"

int main(void){
  U64 bb = 0ULL;
  set_bit(D4, bb);
  set_bit(D5, bb);
  set_bit(E4, bb);
  set_bit(E5, bb);

  print_bitboard(bb);

  return 0;
}
