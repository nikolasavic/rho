#include <string.h>
#include "exits.h"
#include "move_list.h"

void empty_move_list(move_list_t * ml) {
  ml->count = 0;
  memset(ml->moves, 0, sizeof(ml->moves));
}

exit_t add_to_move_list(move_list_t * ml, U16 move) {
  if(ml->count >= MOVE_LIST_CAPACITY) {
    return FAIL;
  }

  ml->moves[ml->count] = move;
  ml->count++;

  return SUCCESS;
}
