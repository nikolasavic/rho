#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "board.h"

board_t empty_board() {
  board_t board;
  memset(&board, 0, sizeof(board_t));
  return board;
}
