#include <stdbool.h>
#include "helpers.h"

bool is_move_in_list(move_list_t* ml, move_t* move) {
  U16 encoded = encode_move(move);
  int iter = 0;

  while(iter < ml->count) {
    if(ml->moves[iter] == encoded)
      return true;
    iter++;
  }

  return false;
}

int count_moves_from_square(move_list_t* ml, square_t target) {
  move_t move;
  int iter = 0;
  int count = 0;

  while(iter < ml->count) {
    decode_move(&move, ml->moves[iter]);
    if(move.origin == target)
      count++;
    iter++;
  }

  return count;
}
