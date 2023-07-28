#ifndef PARSER_H
#define PARSER_H

#include "board.h"
#include "exits.h"

side_t parse_side_to_move(const char);
castle_t parse_castling_rights(const char* );
void parse_piece_char(U64[2][6], char, int);
int parse_string_int(const char* );
square_t parse_square(const char* );
exit_t parse_fen(board_t *, const char* );

#endif
