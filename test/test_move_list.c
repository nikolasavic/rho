#include "../src/move_list.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_empty_move_list(void) {
  move_list_t ml;
  empty_move_list(&ml);
  U16 expected[MOVE_LIST_CAPACITY] = { 0 };

  expected[0] = 0;
  TEST_ASSERT_EQUAL_INT(0, ml.count);
  TEST_ASSERT_EQUAL_INT16_ARRAY(expected, ml.moves, MOVE_LIST_CAPACITY);

  ml.count = 1;
  ml.moves[0] = 1;
  expected[0] = 1;
  TEST_ASSERT_EQUAL_INT(1, ml.count);
  TEST_ASSERT_EQUAL_INT16_ARRAY(expected, ml.moves, MOVE_LIST_CAPACITY);

  empty_move_list(&ml);
  expected[0] = 0;
  TEST_ASSERT_EQUAL_INT(0, ml.count);
  TEST_ASSERT_EQUAL_INT16_ARRAY(expected, ml.moves, MOVE_LIST_CAPACITY);
}
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_empty_move_list);
  UNITY_END();
}
