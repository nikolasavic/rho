#include <stdbool.h>
#include "helpers.h"

bool is_move_in_list(move_list_t * ml, move_t * move) {
  U16 encoded = encode_move(move);
  int iter = 0;

  while(iter < ml->count) {
    if(ml->moves[iter] == encoded)
      return true;
    iter++;
  }

  return false;
}
