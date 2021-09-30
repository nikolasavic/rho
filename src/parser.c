#include <stdio.h>
#include "defs.h"

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
