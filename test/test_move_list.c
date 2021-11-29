#include "../src/exits.h"
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

void test_add_to_move_list(void) {
  move_list_t ml;
  empty_move_list(&ml);
  U16 expected[MOVE_LIST_CAPACITY] = { 0 };
  U16 move = 13;

  expected[0] = move;
  int exit = add_to_move_list(&ml, move);

  TEST_ASSERT_EQUAL_INT(SUCCESS, exit);
  TEST_ASSERT_EQUAL_INT(1, ml.count);
  TEST_ASSERT_EQUAL_INT(move, ml.moves[0]);
  TEST_ASSERT_EQUAL_INT16_ARRAY(expected, ml.moves, MOVE_LIST_CAPACITY);
}

void test_add_to_move_list_capacity(void) {
  move_list_t ml;
  empty_move_list(&ml);
  int exit;

  for(U16 i = 0; i < MOVE_LIST_CAPACITY; i++) {
    exit = add_to_move_list(&ml, i);
    TEST_ASSERT_EQUAL_INT(SUCCESS, exit);
    TEST_ASSERT_EQUAL_INT(i + 1, ml.count);
  }
  TEST_ASSERT_EQUAL_INT(MOVE_LIST_CAPACITY, ml.count);

  exit = add_to_move_list(&ml, 0);
  TEST_ASSERT_EQUAL_INT(FAIL, exit);
  TEST_ASSERT_EQUAL_INT(MOVE_LIST_CAPACITY, ml.count);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_empty_move_list);
  RUN_TEST(test_add_to_move_list);
  RUN_TEST(test_add_to_move_list_capacity);
  UNITY_END();
}
