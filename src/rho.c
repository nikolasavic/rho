#include <stdio.h>
#include "board.h"
#include "parser.h"

int main(void) {
//U64 bb = 0ULL;
//set_bit(D6, bb);
//print_bitboard(bb);

//for(int rank = 7; rank >= 0; rank--) {
//  for(int file = 0; file <= 7; file++) {
//    int square = file + rank * 8;
//    bb = rook_attack_mask(square, 0ULL);
//    print_bitboard(bb);
//  }
//}

  board_t board;
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  print_board(&board);

  return 0;
}
