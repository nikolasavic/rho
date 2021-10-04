#include <stdio.h>
#include "defs.h"
#include "bitboard.h"

side_t parse_side_to_move(const char string) {
  if(string == 'w')
    return WHITE;
  else if(string == 'b')
    return BLACK;
}

castle_t parse_castling_rights(const char *string) {
  int K = 0;
  int Q = 0;
  int k = 0;
  int q = 0;

  const char *str_ptr = string;

  while(*str_ptr != '\0') {
    if(*str_ptr == 'K')
      K = 1;
    if(*str_ptr == 'Q')
      Q = 1;
    if(*str_ptr == 'k')
      k = 1;
    if(*str_ptr == 'q')
      q = 1;
    str_ptr++;
  }

  return ((K << 1 | Q) << 1 | k) << 1 | q;
}

void parse_piece_char(U64 bb_arr[2][6], char piece, int square) {
  int side_lookup[] = {
    ['P'] = WHITE,['B'] = WHITE,['N'] = WHITE,['R'] = WHITE,['Q'] = WHITE,['K'] = WHITE,
    ['p'] = BLACK,['b'] = BLACK,['n'] = BLACK,['r'] = BLACK,['q'] = BLACK,['k'] = BLACK
  };
  int piece_lookup[] = {
    ['P'] = P,['B'] = B,['N'] = N,['R'] = R,['Q'] = Q,['K'] = K,
    ['p'] = P,['b'] = B,['n'] = N,['r'] = R,['q'] = Q,['k'] = K
  };

  int side_idx = side_lookup[piece];
  int piece_idx = piece_lookup[piece];

  bb_arr[side_idx][piece_idx] = set_bit(square, bb_arr[side_idx][piece_idx]);

}
