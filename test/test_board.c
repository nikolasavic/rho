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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_empty_board);
  return UNITY_END();
}
