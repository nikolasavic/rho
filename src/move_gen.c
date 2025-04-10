#include <stdbool.h>
#include "move_gen.h"
#include "init.h"
#include "board.h"
#include "bitboard.h"
#include "masks.h"

void generate_moves(move_list_t* ml, board_t* board, side_t side) {
  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    // king
    if(board->pieces[side][K] & square_to_bitboard[sq]) {
      if(side == WHITE) {
        get_king_psuedo_moves(ml, board, sq, WHITE);
      } else {
        get_king_psuedo_moves(ml, board, sq, BLACK);
      }
    }
    // knight
    if(board->pieces[side][N]
       && board->pieces[side][N] & square_to_bitboard[sq]) {
      if(side == WHITE) {
        get_knight_psuedo_moves(ml, board, sq, WHITE);
      } else {
        get_knight_psuedo_moves(ml, board, sq, BLACK);
      }
    }
    // queen
    if(board->pieces[side][Q]
       && board->pieces[side][Q] & square_to_bitboard[sq]) {
      if(side == WHITE) {
        get_queen_psuedo_moves(ml, board, sq, WHITE);
      } else {
        get_queen_psuedo_moves(ml, board, sq, BLACK);
      }
    }
    // rook
    if(board->pieces[side][R]
       && board->pieces[side][R] & square_to_bitboard[sq]) {
      if(side == WHITE) {
        get_rook_psuedo_moves(ml, board, sq, WHITE);
      } else {
        get_rook_psuedo_moves(ml, board, sq, BLACK);
      }
    }
    // bishop
    if(board->pieces[side][B]
       && board->pieces[side][B] & square_to_bitboard[sq]) {
      if(side == WHITE) {
        get_bishop_psuedo_moves(ml, board, sq, WHITE);
      } else {
        get_bishop_psuedo_moves(ml, board, sq, BLACK);
      }
    }
  }
}

void add_simple_psuedo_moves(move_list_t* ml, board_t* board,
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

void get_knight_psuedo_moves(move_list_t* ml, board_t* board,
                             square_t origin, side_t side) {
  U64 moves = knight_moves[origin];
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_king_psuedo_moves(move_list_t* ml, board_t* board, square_t origin,
                           side_t side) {
  U64 moves = king_moves[origin];
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_rook_psuedo_moves(move_list_t* ml, board_t* board, square_t origin,
                           side_t side) {
  U64 moves = rook_attack_mask(origin, board->occupancy[BOTH]);
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_bishop_psuedo_moves(move_list_t* ml, board_t* board,
                             square_t origin, side_t side) {
  U64 moves = bishop_attack_mask(origin, board->occupancy[BOTH]);
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_queen_psuedo_moves(move_list_t* ml, board_t* board,
                            square_t origin, side_t side) {
  U64 moves = queen_attack_mask(origin, board->occupancy[BOTH]);
  moves &= ~(board->occupancy[side]);
  add_simple_psuedo_moves(ml, board, origin, side, moves);
}

void get_pawn_psuedo_moves(move_list_t* ml, board_t* board, square_t origin,
                           side_t side) {
  move_t move = { 0 };
  square_t target;
  bool quiet;

  U64 moves = pawn_moves[side][origin];
  move.origin = origin;

  while(moves) {
    target = bitscan_fwd(moves);
    quiet = 1;
    move.target = target;
    move.quiet_move = quiet;

    add_to_move_list(ml, encode_move(&move));

    pop_bit(target, moves);
  }
}

void get_castle_psuedo_moves(move_list_t* ml, board_t* board, side_t side) {
  if(side == WHITE) {
    bool kingside_cond =
      !get_bit(F1, board->occupancy[BOTH]) &&
      !get_bit(G1, board->occupancy[BOTH]) &&
      get_bit(E1, board->pieces[side][K]) &&
      get_bit(H1, board->pieces[side][R]);

    if(kingside_cond) {
      move_t kingside = { NULL_SQ, NULL_SQ, 0, 0, 0, 0, 0, 1, 0 };
      add_to_move_list(ml, encode_move(&kingside));
    }

    bool queenside_cond =
      !get_bit(B1, board->occupancy[BOTH]) &&
      !get_bit(C1, board->occupancy[BOTH]) &&
      !get_bit(D1, board->occupancy[BOTH]) &&
      get_bit(E1, board->pieces[side][K]) &&
      get_bit(A1, board->pieces[side][R]);

    if(queenside_cond) {
      move_t queenside = { NULL_SQ, NULL_SQ, 0, 0, 0, 0, 0, 0, 1 };
      queenside.queenside_castle = 1;
      add_to_move_list(ml, encode_move(&queenside));
    }

  } else {
    bool kingside_cond =
      !get_bit(F8, board->occupancy[BOTH]) &&
      !get_bit(G8, board->occupancy[BOTH]) &&
      get_bit(E8, board->pieces[side][K]) &&
      get_bit(H8, board->pieces[side][R]);

    if(kingside_cond) {
      move_t kingside = { NULL_SQ, NULL_SQ, 0, 0, 0, 0, 0, 1, 0 };
      add_to_move_list(ml, encode_move(&kingside));
    }

    bool queenside_cond =
      !get_bit(B8, board->occupancy[BOTH]) &&
      !get_bit(C8, board->occupancy[BOTH]) &&
      !get_bit(D8, board->occupancy[BOTH]) &&
      get_bit(E8, board->pieces[side][K]) &&
      get_bit(A8, board->pieces[side][R]);

    if(queenside_cond) {
      move_t queenside = { NULL_SQ, NULL_SQ, 0, 0, 0, 0, 0, 0, 1 };
      queenside.queenside_castle = 1;
      add_to_move_list(ml, encode_move(&queenside));
    }
  }
}
