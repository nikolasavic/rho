#include <stdio.h>
#include <string.h>
#include "board.h"
#include "bitboard.h"

int piece_identity(int square, board_t * board);

char *square_name[] = {
  "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
  "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
  "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
  "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
  "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
  "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
  "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
  "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "null"
};

char *piece_unicode[] =
  { "♙", "♗", "♘", "♖", "♕", "♔", "♟︎", "♝", "♞", "♜", "♛", "♚" };

char *piece_ascii[] =
  { "P", "B", "N", "R", "Q", "K", "p", "b", "n", "r", "q", "k" };

exit_t validate_board(board_t * board, val_opt_t option) {
  if(board->half_move_clock < 0) {
    if(option == VERBOSE) {
      printf("Error: negative half_move_clock: %d\n", board->half_move_clock);
    }
    return FAIL;
  }

  if(board->full_move_num < 0) {
    if(option == VERBOSE) {
      printf("Error: negative full_move_num: %d\n", board->full_move_num);
    }
    return FAIL;
  }

  if(board->ep_square < 0 || board->ep_square > 64) {
    if(option == VERBOSE) {
      printf("Error: invalid ep_square: %d\n", board->ep_square);
    }
    return FAIL;
  }

  if(board->castle_rights < 0 || board->castle_rights > 15) {
    if(option == VERBOSE) {
      printf("Error: invalid castling rights: %d\n", board->castle_rights);
    }
    return FAIL;
  }

  if(board->side_to_move != 0 && board->side_to_move != 1) {
    if(option == VERBOSE) {
      printf("Error: invalid side to move: %d\n", board->side_to_move);
    }
    return FAIL;
  }

  int found_side;
  int found_piece;
  int square;
  for(int rank = 1; rank <= 8; rank++) {
    for(int file = 1; file <= 8; file++) {
      square = (file - 1) + (rank - 1) * 8;
      found_side = -1;
      found_piece = -1;
      for(int side = 0; side < 2; side++) {
        for(int piece = 0; piece < 6; piece++) {
          if(get_bit(square, board->pieces[side][piece]) == 1) {
            if(found_piece == -1 && found_side == -1) {
              found_side = side;
              found_piece = piece;
            } else {
              if(option == VERBOSE) {
                printf("Error: piece collision on %s\n", square_name[square]);
                printf("side: %c, piece: %s\n", found_side == 0 ? 'w' : 'b',
                       piece_ascii[found_piece]);
                printf("side: %c, piece: %s\n", side == 0 ? 'w' : 'b',
                       piece_ascii[piece]);
              }
              return FAIL;
            }
          }
        }
      }
    }
  }

  return SUCCESS;
}

void print_board(board_t * board) {
  char side_to_move = board->side_to_move == 0 ? 'w' : 'b';
  int piece_idx;
  printf("\n");
  for(int rank = 1; rank <= 8; rank++) {
    printf("%d  ", 9 - rank);
    for(int file = 1; file <= 8; file++) {
      int square = (file - 1) + (rank - 1) * 8;
      piece_idx = piece_identity(square, board);
      if(piece_idx == -1) {
        printf(". ");
      } else {
        printf("%s ", piece_unicode[piece_idx]);
      }

    }
    printf("\n");
  }
  printf("\n   a b c d e f g h\n");
  printf("%c    - Side to move\n", side_to_move);
  printf("%s - Castling rights\n",
         decode_castling_rights(board->castle_rights));
  if(board->ep_square == NULL_SQ) {
    printf("%s - En passant sq\n", square_name[board->ep_square]);
  } else {
    printf("%s   - En passant sq\n", square_name[board->ep_square]);
  }
  printf("%2d   - Half move clock\n", board->half_move_clock);
  printf("%2d   - Move\n", board->full_move_num);
}

int piece_identity(int square, board_t * board) {
  int found = -1;
  for(int side = 0; side < 2; side++) {
    for(int piece = 0; piece < 6; piece++) {
      if(get_bit(square, board->pieces[side][piece]) == 1) {
        found = piece + 6 * side;
      }
    }
  }

  return found;
}

char *decode_castling_rights(int castle_idx) {
  char *castle_rights[] = {
    "-   ", "   q", "  k ", "  kq",
    " Q  ", " Q q", " Qk ", " Qkq",
    "K   ", "K  q", "K k ", "K kq",
    "KQ  ", "KQ q", "KQk ", "KQkq", "null"
  };

  return castle_rights[castle_idx];
}

void empty_board(board_t * board) {
  memset(board, 0, sizeof(board_t));
  board->side_to_move = NULL_SIDE;
  board->ep_square = NULL_SQ;
  board->castle_rights = 16;
}
