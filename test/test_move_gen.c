#include <string.h>
#include "helpers.h"
#include "../src/init.h"
#include "../src/board.h"
#include "../src/move.h"
#include "../src/move_list.h"
#include "../src/move_gen.h"
#include "../src/parser.h"
#include "../unity/unity.h"

board_t board;
move_list_t ml;

void setUp(void) {
  empty_board(&board);
  empty_move_list(&ml);
  init_all();
}

void tearDown(void) {
}

void test_get_knight_psuedo_moves_white(void) {
  parse_fen(&board,
            "r1bqkbnr/ppp2ppp/2n5/3pp3/4P3/2N2N2/PPPP1PPP/R1BQKB1R w KQkq - 2 3");
  set_occupancy(&board);
  square_t square = C3;

  int expected_move_len = 5;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {C3, B1, 0, 1, 0, 0, 0, 0, 0},
    {C3, A4, 0, 1, 0, 0, 0, 0, 0},
    {C3, B5, 0, 1, 0, 0, 0, 0, 0},
    {C3, E2, 0, 1, 0, 0, 0, 0, 0},
    {C3, D5, 0, 0, 0, 1, 0, 0, 0},
  };

  get_knight_psuedo_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_knight_psuedo_moves_black(void) {
  parse_fen(&board, "5k2/8/4np2/4p1n1/5P2/6P1/6K1/4R3 b - - 0 1");
  set_occupancy(&board);
  square_t square = E6;

  int expected_move_len = 6;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {E6, D8, 0, 1, 0, 0, 0, 0, 0},
    {E6, C7, 0, 1, 0, 0, 0, 0, 0},
    {E6, C5, 0, 1, 0, 0, 0, 0, 0},
    {E6, D4, 0, 1, 0, 0, 0, 0, 0},
    {E6, F4, 0, 0, 0, 1, 0, 0, 0},
    {E6, G7, 0, 1, 0, 0, 0, 0, 0},
  };

  get_knight_psuedo_moves(&ml, &board, square, BLACK);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_knight_psuedo_moves_no_moves(void) {
  parse_fen(&board, "4r3/6n1/4k1p1/5p1p/2nP1K1P/2P3P1/1P2N3/2B3N1 w - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 0;

  square_t square = E2;
  get_knight_psuedo_moves(&ml, &board, square, WHITE);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);

  square = G7;
  get_knight_psuedo_moves(&ml, &board, square, BLACK);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
}

void test_get_king_psuedo_moves_white(void) {
  parse_fen(&board, "8/1k6/8/1Pp5/2K5/8/8/8 w - - 0 1");
  set_occupancy(&board);
  square_t square = C4;

  int expected_move_len = 7;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {C4, C5, 0, 0, 0, 1, 0, 0, 0},
    {C4, D5, 0, 1, 0, 0, 0, 0, 0},
    {C4, D4, 0, 1, 0, 0, 0, 0, 0},
    {C4, D3, 0, 1, 0, 0, 0, 0, 0},
    {C4, C3, 0, 1, 0, 0, 0, 0, 0},
    {C4, B3, 0, 1, 0, 0, 0, 0, 0},
    {C4, B4, 0, 1, 0, 0, 0, 0, 0},
  };

  get_king_psuedo_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_king_psuedo_moves_black(void) {
  parse_fen(&board, "8/1k6/8/1Pp5/2K5/8/8/8 b - - 0 1");
  set_occupancy(&board);
  square_t square = B7;

  int expected_move_len = 8;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {B7, A8, 0, 1, 0, 0, 0, 0, 0},
    {B7, B8, 0, 1, 0, 0, 0, 0, 0},
    {B7, C8, 0, 1, 0, 0, 0, 0, 0},
    {B7, A7, 0, 1, 0, 0, 0, 0, 0},
    {B7, C7, 0, 1, 0, 0, 0, 0, 0},
    {B7, A6, 0, 1, 0, 0, 0, 0, 0},
    {B7, B6, 0, 1, 0, 0, 0, 0, 0},
    {B7, C6, 0, 1, 0, 0, 0, 0, 0},
  };

  get_king_psuedo_moves(&ml, &board, square, BLACK);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_king_psuedo_moves_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  int expected_move_len = 0;

  square_t square = E1;
  get_king_psuedo_moves(&ml, &board, square, WHITE);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);

  square = E8;
  get_king_psuedo_moves(&ml, &board, square, BLACK);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
}

void test_get_rook_psuedo_moves_white(void) {
  parse_fen(&board, "8/6P1/3k2r1/3P4/3KR3/8/4p3/8 w - - 0 1");
  set_occupancy(&board);
  square_t square = E4;

  int expected_move_len = 9;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {E4, E8, 0, 1, 0, 0, 0, 0, 0},
    {E4, E7, 0, 1, 0, 0, 0, 0, 0},
    {E4, E6, 0, 1, 0, 0, 0, 0, 0},
    {E4, E5, 0, 1, 0, 0, 0, 0, 0},
    {E4, E3, 0, 1, 0, 0, 0, 0, 0},
    {E4, E2, 0, 0, 0, 1, 0, 0, 0},
    {E4, F4, 0, 1, 0, 0, 0, 0, 0},
    {E4, G4, 0, 1, 0, 0, 0, 0, 0},
    {E4, H4, 0, 1, 0, 0, 0, 0, 0},
  };

  get_rook_psuedo_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_rook_psuedo_moves_black(void) {
  parse_fen(&board, "8/6P1/3k2r1/3P4/3KR3/8/4p3/8 b - - 0 1");
  set_occupancy(&board);
  square_t square = G6;

  int expected_move_len = 9;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {G6, G7, 0, 0, 0, 1, 0, 0, 0},
    {G6, G5, 0, 1, 0, 0, 0, 0, 0},
    {G6, G4, 0, 1, 0, 0, 0, 0, 0},
    {G6, G3, 0, 1, 0, 0, 0, 0, 0},
    {G6, G2, 0, 1, 0, 0, 0, 0, 0},
    {G6, G1, 0, 1, 0, 0, 0, 0, 0},
    {G6, H6, 0, 1, 0, 0, 0, 0, 0},
    {G6, F6, 0, 1, 0, 0, 0, 0, 0},
    {G6, E6, 0, 1, 0, 0, 0, 0, 0},
  };

  get_rook_psuedo_moves(&ml, &board, square, BLACK);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_rook_psuedo_moves_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  int expected_move_len = 0;

  square_t square = A1;
  get_rook_psuedo_moves(&ml, &board, square, WHITE);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);

  square = H8;
  get_rook_psuedo_moves(&ml, &board, square, BLACK);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
}

void test_get_bishop_psuedo_moves_white(void) {
  parse_fen(&board, "8/8/3pp3/3b1k2/3K1B2/4PP2/8/8 w - - 0 1");
  set_occupancy(&board);

  square_t square = F4;

  int expected_move_len = 6;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {F4, E5, 0, 1, 0, 0, 0, 0, 0},
    {F4, D6, 0, 0, 0, 1, 0, 0, 0},
    {F4, G5, 0, 1, 0, 0, 0, 0, 0},
    {F4, H6, 0, 1, 0, 0, 0, 0, 0},
    {F4, G3, 0, 1, 0, 0, 0, 0, 0},
    {F4, H2, 0, 1, 0, 0, 0, 0, 0},
  };

  get_bishop_psuedo_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_bishop_psuedo_moves_black(void) {
  parse_fen(&board, "8/8/3pp3/3b1k2/3K1B2/4PP2/8/8 b - - 0 1");
  set_occupancy(&board);

  square_t square = D5;

  int expected_move_len = 8;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {D5, E4, 0, 1, 0, 0, 0, 0, 0},
    {D5, F3, 0, 0, 0, 1, 0, 0, 0},
    {D5, C4, 0, 1, 0, 0, 0, 0, 0},
    {D5, B3, 0, 1, 0, 0, 0, 0, 0},
    {D5, A2, 0, 1, 0, 0, 0, 0, 0},
    {D5, C6, 0, 1, 0, 0, 0, 0, 0},
    {D5, B7, 0, 1, 0, 0, 0, 0, 0},
    {D5, A8, 0, 1, 0, 0, 0, 0, 0},
  };

  get_bishop_psuedo_moves(&ml, &board, square, BLACK);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_bishop_psuedo_moves_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  int expected_move_len = 0;

  square_t square = C1;
  get_bishop_psuedo_moves(&ml, &board, square, WHITE);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);

  square = C8;
  get_bishop_psuedo_moves(&ml, &board, square, BLACK);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
}

void test_get_queen_psuedo_moves_white(void) {
  parse_fen(&board, "8/8/8/6QK/6N1/8/3qkn2/8 w - - 0 1");
  set_occupancy(&board);

  square_t square = G5;

  int expected_move_len = 17;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {G5, H6, 0, 1, 0, 0, 0, 0, 0},
    {G5, H4, 0, 1, 0, 0, 0, 0, 0},
    {G5, G6, 0, 1, 0, 0, 0, 0, 0},
    {G5, G7, 0, 1, 0, 0, 0, 0, 0},
    {G5, G8, 0, 1, 0, 0, 0, 0, 0},
    {G5, F6, 0, 1, 0, 0, 0, 0, 0},
    {G5, E7, 0, 1, 0, 0, 0, 0, 0},
    {G5, D8, 0, 1, 0, 0, 0, 0, 0},
    {G5, F5, 0, 1, 0, 0, 0, 0, 0},
    {G5, E5, 0, 1, 0, 0, 0, 0, 0},
    {G5, D5, 0, 1, 0, 0, 0, 0, 0},
    {G5, C5, 0, 1, 0, 0, 0, 0, 0},
    {G5, B5, 0, 1, 0, 0, 0, 0, 0},
    {G5, A5, 0, 1, 0, 0, 0, 0, 0},
    {G5, F4, 0, 1, 0, 0, 0, 0, 0},
    {G5, E3, 0, 1, 0, 0, 0, 0, 0},
    {G5, D2, 0, 0, 0, 1, 0, 0, 0},
  };

  get_queen_psuedo_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_queen_psuedo_moves_black(void) {
  parse_fen(&board, "8/8/8/6QK/6N1/8/3qkn2/8 b - - 0 1");
  set_occupancy(&board);

  square_t square = D2;

  int expected_move_len = 18;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {D2, D1, 0, 1, 0, 0, 0, 0, 0},
    {D2, E1, 0, 1, 0, 0, 0, 0, 0},
    {D2, C1, 0, 1, 0, 0, 0, 0, 0},
    {D2, C2, 0, 1, 0, 0, 0, 0, 0},
    {D2, B2, 0, 1, 0, 0, 0, 0, 0},
    {D2, A2, 0, 1, 0, 0, 0, 0, 0},
    {D2, C3, 0, 1, 0, 0, 0, 0, 0},
    {D2, B4, 0, 1, 0, 0, 0, 0, 0},
    {D2, A5, 0, 1, 0, 0, 0, 0, 0},
    {D2, D3, 0, 1, 0, 0, 0, 0, 0},
    {D2, D4, 0, 1, 0, 0, 0, 0, 0},
    {D2, D5, 0, 1, 0, 0, 0, 0, 0},
    {D2, D6, 0, 1, 0, 0, 0, 0, 0},
    {D2, D7, 0, 1, 0, 0, 0, 0, 0},
    {D2, D8, 0, 1, 0, 0, 0, 0, 0},
    {D2, E3, 0, 1, 0, 0, 0, 0, 0},
    {D2, F4, 0, 1, 0, 0, 0, 0, 0},
    {D2, G5, 0, 0, 0, 1, 0, 0, 0},
  };

  get_queen_psuedo_moves(&ml, &board, square, BLACK);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_get_queen_psuedo_moves_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  int expected_move_len = 0;

  square_t square = D1;
  get_queen_psuedo_moves(&ml, &board, square, WHITE);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);

  square = D8;
  get_queen_psuedo_moves(&ml, &board, square, BLACK);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_knight_psuedo_moves_white);
  RUN_TEST(test_get_knight_psuedo_moves_black);
  RUN_TEST(test_get_knight_psuedo_moves_no_moves);
  RUN_TEST(test_get_king_psuedo_moves_white);
  RUN_TEST(test_get_king_psuedo_moves_black);
  RUN_TEST(test_get_king_psuedo_moves_no_moves);
  RUN_TEST(test_get_rook_psuedo_moves_white);
  RUN_TEST(test_get_rook_psuedo_moves_black);
  RUN_TEST(test_get_rook_psuedo_moves_no_moves);
  RUN_TEST(test_get_bishop_psuedo_moves_white);
  RUN_TEST(test_get_bishop_psuedo_moves_black);
  RUN_TEST(test_get_bishop_psuedo_moves_no_moves);
  RUN_TEST(test_get_queen_psuedo_moves_white);
  RUN_TEST(test_get_queen_psuedo_moves_black);
  RUN_TEST(test_get_queen_psuedo_moves_no_moves);
  return UNITY_END();
}
