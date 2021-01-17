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

void test_pawn_motion_mask(void) {
  U64 expected;

  expected = 0ULL;
  set_bit(D3, expected);
  set_bit(D4, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(D2, WHITE));

  expected = 0ULL;
  set_bit(B4, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(B3, WHITE));

  expected = 0ULL;
  set_bit(A7, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(A6, WHITE));

  expected = 0ULL;
  set_bit(C8, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(C7, WHITE));

  expected = 0ULL;
  set_bit(G6, expected);
  set_bit(G5, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(G7, BLACK));

  expected = 0ULL;
  set_bit(B5, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(B6, BLACK));

  expected = 0ULL;
  set_bit(C4, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(C5, BLACK));

  expected = 0ULL;
  set_bit(H3, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(H4, BLACK));

  expected = 0ULL;
  set_bit(A2, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(A3, BLACK));

  expected = 0ULL;
  set_bit(F1, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(F2, BLACK));

  TEST_ASSERT_EQUAL_INT(0ULL, pawn_motion_mask(A1, WHITE));
  TEST_ASSERT_EQUAL_INT(0ULL, pawn_motion_mask(A1, BLACK));
  TEST_ASSERT_EQUAL_INT(0ULL, pawn_motion_mask(H8, WHITE));
  TEST_ASSERT_EQUAL_INT(0ULL, pawn_motion_mask(H8, BLACK));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_pawn_attack_mask);
  RUN_TEST(test_pawn_motion_mask);
  return UNITY_END();
}
