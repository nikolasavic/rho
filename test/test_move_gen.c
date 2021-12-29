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
  parse_fen(&board, "8/1k6/8/1Pp5/2K5/8/8/8 w - - 0 1");
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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_knight_psuedo_moves_white);
  RUN_TEST(test_get_knight_psuedo_moves_black);
  RUN_TEST(test_get_king_psuedo_moves_white);
  RUN_TEST(test_get_king_psuedo_moves_black);
  return UNITY_END();
}
