#include "../src/defs.h"
#include "../src/board.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_empty_board(void) {
  board_t b = empty_board();
  TEST_ASSERT_EQUAL_INT(0, b.side_to_move);
  TEST_ASSERT_EQUAL_INT(0, b.castle_rights);

  for(int side = 0; side < 2; side++) {
    for(int piece = 0; piece < 6; piece++) {
      TEST_ASSERT_EQUAL_INT(0, b.pieces[side][piece]);
    }
  }
}

void test_validate_board(void) {
  board_t board = {0};
  board.pieces[BLACK][P] = 268959744ULL;
  board.pieces[BLACK][N] = 137438953472ULL;
  board.pieces[BLACK][B] = 512ULL;
  board.pieces[BLACK][R] = 129ULL;
  board.pieces[BLACK][Q] = 2048ULL;
  board.pieces[BLACK][K] = 64ULL;
  board.pieces[WHITE][P] = 4501125726208ULL;
  board.pieces[WHITE][N] = 35184372088832ULL;
  board.pieces[WHITE][B] = 70385924046848ULL;
  board.pieces[WHITE][R] = 9295429630892703744ULL;
  board.pieces[WHITE][Q] = 576460752303423488ULL;
  board.pieces[WHITE][K] = 18014398509481984ULL;
  board.ep_square = E6;
  board.half_move_clock = 7;
  board.full_move_num = 15;

  TEST_ASSERT_EQUAL_INT(0,validate_board(board));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_empty_board);
  RUN_TEST(test_validate_board);
  return UNITY_END();
}
