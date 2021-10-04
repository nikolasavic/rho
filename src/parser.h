#ifndef PARSER_H
#define PARSER_H

side_t parse_side_to_move(const char);
castle_t parse_castling_rights(const char *);
void parse_piece_char(U64[2][6], char, int);

#endif
