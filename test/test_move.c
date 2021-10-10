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

void test_empty_move_is_invalid(void) {
  move_t move = { 0 };

  TEST_ASSERT_EQUAL_INT(FAIL, validate_move(&move, SILENT));
}

void test_empty_move(void) {
  move_t move = { 0 };

  TEST_ASSERT_EQUAL_INT(A8, move.origin);
  TEST_ASSERT_EQUAL_INT(A8, move.target);
  TEST_ASSERT_EQUAL_INT(P, move.promotion);
  TEST_ASSERT_EQUAL_INT(false, move.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, move.double_pawn);
  TEST_ASSERT_EQUAL_INT(false, move.capture);
  TEST_ASSERT_EQUAL_INT(false, move.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, move.queenside_castle);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_validate_move);
  RUN_TEST(test_empty_move_is_invalid);
  RUN_TEST(test_empty_move);
  return UNITY_END();
}
