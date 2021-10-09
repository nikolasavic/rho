#ifndef BOARD_H
#define BOARD_H

#include "bitboard.h"
#include "exits.h"
#include "options.h"

typedef enum {
  A8, B8, C8, D8, E8, F8, G8, H8,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A1, B1, C1, D1, E1, F1, G1, H1, NULL_SQ
} square_t;

typedef unsigned char castle_t;

typedef enum {
  WHITE, BLACK, NULL_SIDE
} side_t;

typedef enum piece_e {
  P, B, N, R, Q, K, NULL_P
} piece_t;

typedef struct board_s {
  side_t side_to_move;
  castle_t castle_rights;
  U64 pieces[2][6];
  square_t ep_square;
  int half_move_clock;
  int full_move_num;
} board_t;

extern char *square_name[];
extern int square_to_rank[];
extern int square_to_file[];
extern char *piece_unicode[];
extern char *piece_ascii[];

void empty_board(board_t *);
exit_t validate_board(board_t *, val_opt_t);
char *decode_castling_rights(int);

#endif
