#ifndef MOVE_GEN_H
#define MOVE_GEN_H

#include "bitboard.h"
#include "move_list.h"
#include "board.h"

void get_knight_psuedo_moves(move_list_t *, board_t *, square_t, side_t);
void get_king_psuedo_moves(move_list_t *, board_t *, square_t, side_t);
void get_rook_psuedo_moves(move_list_t *, board_t *, square_t, side_t);
void get_bishop_psuedo_moves(move_list_t *, board_t *, square_t, side_t);
void get_queen_psuedo_moves(move_list_t *, board_t *, square_t, side_t);
void get_pawn_psuedo_moves(move_list_t *, board_t *, square_t, side_t);
void get_castle_psuedo_moves(move_list_t *, board_t *, side_t);

#endif
