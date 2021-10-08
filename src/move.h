#ifndef MOVE_H
#define MOVE_H

#include <stdbool.h>

typedef unsigned short int U16;

struct move_s {
  square_t origin;
  square_t target;
  piece_t promotion;
  bool quiet_move;
  bool capture;
  bool ep_capture;
  bool kingside_castle
  bool queenside_castle
} move_t;

#endif
