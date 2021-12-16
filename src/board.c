#include <stdio.h>
#include <string.h>
#include "board.h"
#include "bitboard.h"

int piece_identity(int square, board_t * board);

char *square_name[] = {
  "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
  "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
  "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
  "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
  "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
  "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
  "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
  "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "null"
};

int square_to_rank[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3,
  4, 4, 4, 4, 4, 4, 4, 4,
  5, 5, 5, 5, 5, 5, 5, 5,
  6, 6, 6, 6, 6, 6, 6, 6,
  7, 7, 7, 7, 7, 7, 7, 7,
};

int square_to_file[] = {
  0, 1, 2, 3, 4, 5, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7,
};

U64 square_to_bitboard[64] = {
  1ULL,
  2ULL,
  4ULL,
  8ULL,
  16ULL,
  32ULL,
  64ULL,
  128ULL,
  256ULL,
  512ULL,
  1024ULL,
  2048ULL,
  4096ULL,
  8192ULL,
  16384ULL,
  32768ULL,
  65536ULL,
  131072ULL,
  262144ULL,
  524288ULL,
  1048576ULL,
  2097152ULL,
  4194304ULL,
  8388608ULL,
  16777216ULL,
  33554432ULL,
  67108864ULL,
  134217728ULL,
  268435456ULL,
  536870912ULL,
  1073741824ULL,
  2147483648ULL,
  4294967296ULL,
  8589934592ULL,
  17179869184ULL,
  34359738368ULL,
  68719476736ULL,
  137438953472ULL,
  274877906944ULL,
  549755813888ULL,
  1099511627776ULL,
  2199023255552ULL,
  4398046511104ULL,
  8796093022208ULL,
  17592186044416ULL,
  35184372088832ULL,
  70368744177664ULL,
  140737488355328ULL,
  281474976710656ULL,
  562949953421312ULL,
  1125899906842624ULL,
  2251799813685248ULL,
  4503599627370496ULL,
  9007199254740992ULL,
  18014398509481984ULL,
  36028797018963968ULL,
  72057594037927936ULL,
  144115188075855872ULL,
  288230376151711744ULL,
  576460752303423488ULL,
  1152921504606846976ULL,
  2305843009213693952ULL,
  4611686018427387904ULL,
  9223372036854775808ULL,
};

char *piece_unicode[] = {
  "♙", "♗", "♘", "♖", "♕", "♔",
  "♟︎", "♝", "♞", "♜", "♛", "♚",
};

char *piece_ascii[] = {
  "P", "B", "N", "R", "Q", "K", "p", "b", "n", "r", "q", "k"
};

void set_occupancy(board_t * b) {
  for(int i = 0; i < 6; i++) {
    b->occupancy[WHITE] |= b->pieces[WHITE][i];
    b->occupancy[BLACK] |= b->pieces[BLACK][i];
  }
  b->occupancy[BOTH] = b->occupancy[WHITE] | b->occupancy[BLACK];
}

exit_t validate_board(board_t * board, val_opt_t option) {
  if(board->half_move_clock < 0) {
    if(option == VERBOSE) {
      printf("Error: negative half_move_clock: %d\n", board->half_move_clock);
    }
    return FAIL;
  }

  if(board->full_move_num < 0) {
    if(option == VERBOSE) {
      printf("Error: negative full_move_num: %d\n", board->full_move_num);
    }
    return FAIL;
  }

  if(board->ep_square < 0 || board->ep_square > 64) {
    if(option == VERBOSE) {
      printf("Error: invalid ep_square: %d\n", board->ep_square);
    }
    return FAIL;
  }

  if(board->castle_rights < 0 || board->castle_rights > 15) {
    if(option == VERBOSE) {
      printf("Error: invalid castling rights: %d\n", board->castle_rights);
    }
    return FAIL;
  }

  if(board->side_to_move != 0 && board->side_to_move != 1) {
    if(option == VERBOSE) {
      printf("Error: invalid side to move: %d\n", board->side_to_move);
    }
    return FAIL;
  }

  int found_side;
  int found_piece;
  int square;
  for(int rank = 1; rank <= 8; rank++) {
    for(int file = 1; file <= 8; file++) {
      square = (file - 1) + (rank - 1) * 8;
      found_side = -1;
      found_piece = -1;
      for(int side = 0; side < 2; side++) {
        for(int piece = 0; piece < 6; piece++) {
          if(get_bit(square, board->pieces[side][piece]) == 1) {
            if(found_piece == -1 && found_side == -1) {
              found_side = side;
              found_piece = piece;
            } else {
              if(option == VERBOSE) {
                printf("Error: piece collision on %s\n", square_name[square]);
                printf("side: %c, piece: %s\n", found_side == 0 ? 'w' : 'b',
                       piece_ascii[found_piece]);
                printf("side: %c, piece: %s\n", side == 0 ? 'w' : 'b',
                       piece_ascii[piece]);
              }
              return FAIL;
            }
          }
        }
      }
    }
  }

  return SUCCESS;
}

void print_board(board_t * board) {
  char side_to_move = board->side_to_move == 0 ? 'w' : 'b';
  int piece_idx;
  printf("\n");
  for(int rank = 8; rank >= 1; rank--) {
    printf("%d  ", rank);
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
  printf("%c    - Side to move\n", side_to_move);
  printf("%s - Castling rights\n",
         decode_castling_rights(board->castle_rights));
  if(board->ep_square == NULL_SQ) {
    printf("%s - En passant sq\n", square_name[board->ep_square]);
  } else {
    printf("%s   - En passant sq\n", square_name[board->ep_square]);
  }
  printf("%2d   - Half move clock\n", board->half_move_clock);
  printf("%2d   - Move\n", board->full_move_num);
}

int piece_identity(int square, board_t * board) {
  int found = -1;
  for(int side = 0; side < 2; side++) {
    for(int piece = 0; piece < 6; piece++) {
      if(get_bit(square, board->pieces[side][piece]) == 1) {
        found = piece + 6 * side;
      }
    }
  }

  return found;
}

char *decode_castling_rights(int castle_idx) {
  char *castle_rights[] = {
    "-   ", "   q", "  k ", "  kq",
    " Q  ", " Q q", " Qk ", " Qkq",
    "K   ", "K  q", "K k ", "K kq",
    "KQ  ", "KQ q", "KQk ", "KQkq", "null"
  };

  return castle_rights[castle_idx];
}

void empty_board(board_t * board) {
  memset(board, 0, sizeof(board_t));
  board->side_to_move = NULL_SIDE;
  board->ep_square = NULL_SQ;
  board->castle_rights = 16;
}
