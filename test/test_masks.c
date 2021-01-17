#include "../src/masks.h"
#include "../src/bitboard.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_pawn_attack_mask(void) {
  U64 expected;

  expected = 0ULL;
  set_bit(D3, expected);
  set_bit(F3, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_attack_mask(E2, WHITE));

  expected = 0ULL;
  set_bit(B3, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_attack_mask(A2, WHITE));

  expected = 0ULL;
  set_bit(G3, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_attack_mask(H2, WHITE));

  expected = 0ULL;
  set_bit(F6, expected);
  set_bit(H6, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_attack_mask(G7, BLACK));

  expected = 0ULL;
  set_bit(B6, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_attack_mask(A7, BLACK));

  expected = 0ULL;
  set_bit(G6, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_attack_mask(H7, BLACK));

  TEST_ASSERT_EQUAL_INT(0ULL, pawn_attack_mask(E1, WHITE));
  TEST_ASSERT_EQUAL_INT(0ULL, pawn_attack_mask(E1, BLACK));
  TEST_ASSERT_EQUAL_INT(0ULL, pawn_attack_mask(D8, WHITE));
  TEST_ASSERT_EQUAL_INT(0ULL, pawn_attack_mask(D8, BLACK));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_pawn_attack_mask);
  return UNITY_END();
}
