#ifndef MOVE_LIST_H
#define MOVE_LIST_H

#include "exits.h"
#include "move_list.h"
#include "move.h"

#define MOVE_LIST_CAPACITY 128

typedef struct move_list_s {
  U16 moves[MOVE_LIST_CAPACITY];
  int count;
} move_list_t;

void empty_move_list(move_list_t *);
exit_t add_to_move_list(move_list_t *, U16);

#endif
