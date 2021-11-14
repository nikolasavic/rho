#ifndef INIT_H
#define INIT_H

#include "bitboard.h"

extern int initialized;

void init_rays(void);
void init_king_moves(void);
void init_knight_moves(void);
void init_pawn_moves(void);
void init_pawn_attacks(void);
void init_all(void);

#endif
