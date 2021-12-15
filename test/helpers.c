#include <stdbool.h>
#include "helpers.h"

bool is_move_in_list(move_list_t * ml, move_t * move) {
  U16 encoded = encode_move(move);
  int iter = 0;

  printf("\ncount: %d\n", ml->count);
  printf("test move: %d\n", encoded);
  print_move(move);

  while(iter < ml->count) {
    printf("encoded move: %d\n", ml->moves[iter]);
    print_encoded_move(ml->moves[iter]);

    if(ml->moves[iter] == encoded)
      return true;
    iter++;
  }

  return false;
}
