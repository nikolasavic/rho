#include <string.h>
#include "move_list.h"

void empty_move_list(move_list_t * ml) {
  ml->count = 0;
  memset(ml->moves, 0, sizeof(ml->moves));
}
