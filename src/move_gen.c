#include <stdbool.h>
#include "move_gen.h"
#include "init.h"
#include "board.h"
#include "bitboard.h"
#include "masks.h"

void add_simple_psuedo_moves(move_list_t * ml, board_t * board,
                             square_t origin, side_t side, U64 attack_moves) {
  U64 target_bb;
  move_t move = { 0 };
  square_t target;
  bool capture;
  bool quiet;

  move.origin = origin;

  while(attack_moves) {
    target = bitscan_fwd(attack_moves);
    target_bb = square_to_bitboard[target];
    capture = target_bb & board->occupancy[!side];
    quiet = !capture;
    move.target = target;
    move.capture = capture;
    move.quiet_move = quiet;

    add_to_move_list(ml, encode_move(&move));

    pop_bit(target, attack_moves);
  }
}

void get_knight_psuedo_moves(move_list_t * ml, board_t * board,
                             square_t origin, side_t side) {
  U64 moves = knight_moves[origin];
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_king_psuedo_moves(move_list_t * ml, board_t * board, square_t origin,
                           side_t side) {
  U64 moves = king_moves[origin];
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_rook_psuedo_moves(move_list_t * ml, board_t * board, square_t origin,
                           side_t side) {
  U64 moves = rook_attack_mask(origin, board->occupancy[BOTH]);
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_bishop_psuedo_moves(move_list_t * ml, board_t * board,
                             square_t origin, side_t side) {
  U64 moves = bishop_attack_mask(origin, board->occupancy[BOTH]);
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_queen_psuedo_moves(move_list_t * ml, board_t * board,
                            square_t origin, side_t side) {
  U64 moves = queen_attack_mask(origin, board->occupancy[BOTH]);
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_pawn_psuedo_moves(move_list_t * ml, board_t * board, square_t origin,
                           side_t side) {
  move_t move = { 0 };
  square_t target;
  bool quiet;

  U64 moves = pawn_moves[side][origin];
  move.origin = origin;

  print_bitboard(moves);
  while(moves) {
    target = bitscan_fwd(moves);
    quiet = 1;
    move.target = target;
    move.quiet_move = quiet;

    add_to_move_list(ml, encode_move(&move));

    pop_bit(target, moves);
  }
}
