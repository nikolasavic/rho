#ifndef HELPERS_H
#define HELPERS_H

#include "../src/move.h"
#include "../src/move_list.h"

bool is_move_in_list(move_list_t *, move_t *);
int count_moves_from_square(move_list_t *, square_t);

#endif
