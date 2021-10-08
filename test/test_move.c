#include "../src/move.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_validate_move(void) {
  move_t move;
  move.origin = E2;
  move.target = E4;
  move.promotion = NULL_P;
  move.quiet_move = true;
  move.double_pawn = true;
  move.capture = false;
  move.ep_capture = false;
  move.kingside_castle = false;
  move.queenside_castle = false;

  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_validate_move);
  return UNITY_END();
}
