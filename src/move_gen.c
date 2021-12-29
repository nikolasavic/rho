#include <stdbool.h>
#include "move_gen.h"
#include "init.h"
#include "board.h"
#include "bitboard.h"

void get_knight_psuedo_moves(move_list_t * ml, board_t * board, square_t origin,
                      side_t side) {
  U64 target_bb;
  move_t move = { 0 };
  square_t target;
  bool capture;
  bool quiet;

  move.origin = origin;
  U64 moves = knight_moves[origin];
  moves &= ~(board->occupancy[side]);

  while(moves) {
    target = bitscan_fwd(moves);
    target_bb = square_to_bitboard[target];
    capture = target_bb & board->occupancy[!side];
    quiet = !capture;
    move.target = target;
    move.capture = capture;
    move.quiet_move = quiet;

    add_to_move_list(ml, encode_move(&move));

    pop_bit(target, moves);
  }
}
