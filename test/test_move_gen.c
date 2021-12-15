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

void test_get_knight_moves(void) {
  parse_fen(&board,
            "r1bqkbnr/ppp2ppp/2n5/3pp3/4P3/2N2N2/PPPP1PPP/R1BQKB1R w KQkq - 2 3");
  square_t square = C3;
  int expected_move_len = 5;
  move_t expected_moves[] = {
    {C3, B1, 0, 1, 0, 0, 0, 0, 0},
    {C3, A4, 0, 1, 0, 0, 0, 0, 0},
    {C3, B5, 0, 1, 0, 0, 0, 0, 0},
    {C3, E2, 0, 1, 0, 0, 0, 0, 0},
    {C3, D5, 0, 0, 0, 1, 0, 0, 0},
  };

  print_move(&expected_moves[0]);

  set_occupancy(&board);
  get_knight_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
  for(int i = 0; i < expected_move_len; i++) {
    print_encoded_move(ml.moves[i]);
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_knight_moves);
  return UNITY_END();
}
