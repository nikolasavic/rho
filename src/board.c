#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "board.h"
#include "bitboard.h"

int piece_identity(int square, board_t board);

void print_board(board_t board) {
  char side_to_move = board.side_to_move ? 'w' : 'b';
  int piece_idx;
  printf("\n");
  for(int rank = 1; rank <= 8; rank++) {
    printf("%d  ", 9 - rank);
    for(int file = 1; file <= 8; file++) {
      int square = (file - 1) + (rank - 1) * 8;
      piece_idx = piece_identity(square, board);
      if(piece_idx == -1) {
        printf(". ");
      } else {
        printf("%s ", piece_unicode[piece_idx]);
      }

    }
    printf("\n");
  }
  printf("\n   a b c d e f g h\n");
  printf("%c   - Side to move\n", side_to_move);
  printf("%s  - En passant sq\n", square_name[board.ep_square]);
  printf("%2d  - Half move clock\n", board.half_move_clock);
  printf("%2d  - Move\n", board.full_move_num);
}

int piece_identity(int square, board_t board) {
  int found = -1;
  for(int side = 0; side < 2; side++) {
    for(int piece = 0; piece < 6; piece++) {
      if(get_bit(square, board.pieces[side][piece]) == 1) {
        found = piece + 6 * side;
      }
    }
  }

  return found;
}

board_t empty_board() {
  board_t board;
  memset(&board, 0, sizeof(board_t));
  return board;
}
