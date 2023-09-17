#ifndef BOARD_ANALYTICS_H
#define BOARD_ANALYTICS_H

#include <stdbool.h>
#include "board.h"
#include "move.h"

bool is_square_attacked(board_t * board, square_t square, side_t side);

#endif
