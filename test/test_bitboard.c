#include "../src/defs.h"
#include "../src/bitboard.h"
#include "../src/board.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_pop_count_empty_bitboard(void) {
  U64 bb = 0ULL;

  TEST_ASSERT_EQUAL_INT(0, pop_count(bb));
}

void test_pop_count_non_empty_bitboard(void) {
  U64 bb = 0ULL;

  set_bit(E4, bb);
  set_bit(C2, bb);
  set_bit(F6, bb);

  TEST_ASSERT_EQUAL_INT(3, pop_count(bb));
}

void test_pop_count_full_bitboard(void) {
  U64 bb = ~0ULL;

  TEST_ASSERT_EQUAL_INT(64, pop_count(bb));
}

void test_pop_bit() {
  U64 bb = ~0ULL;


  TEST_ASSERT_EQUAL_INT(1, get_bit(E4, bb));
  pop_bit(E4, bb);
  TEST_ASSERT_EQUAL_INT(0, get_bit(E4, bb));

  pop_bit(E4, bb);
  TEST_ASSERT_EQUAL_INT(0, get_bit(E4, bb));

  TEST_ASSERT_EQUAL_INT(1, get_bit(F3, bb));
  pop_bit(F3, bb);
  TEST_ASSERT_EQUAL_INT(0, get_bit(F3, bb));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_pop_count_empty_bitboard);
  RUN_TEST(test_pop_count_non_empty_bitboard);
  RUN_TEST(test_pop_count_full_bitboard);
  RUN_TEST(test_pop_bit);
  return UNITY_END();
}
