#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "bitboard.h"
#include "board.h"

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

int parse_string_int(const char *string) {
  const char *str_ptr = string;
  int len = 0;
  int result = 0;
  int value = 0;
  int multiple = 1;

  while(*str_ptr != ' ' && *str_ptr != '\0') {
    len++;
    str_ptr++;
  }
  str_ptr--;

  for(int i = 0; i < len; i++) {
    if(*str_ptr >= '0' && *str_ptr <= '9') {
      value = *str_ptr - 48;
    }
    result += value * multiple;
    multiple *= 10;
    str_ptr--;
  }

  return result;
}

square_t parse_square(const char *string) {
  int files[] = {
    ['a'] = 0,['b'] = 1,['c'] = 2,['d'] = 3,['e'] = 4,['f'] = 5,['g'] = 6,['h'] = 7
  };

  int file = files[*string];
  int rank = (*(string + 1) - 48);
  return (8 - rank) * 8 + file;
}

