#include "../src/bitboard.h"
#include "../src/board.h"
#include "../unity/unity.h"

U64 bb;

void setUp(void) {
  bb = 0ULL;
}

void tearDown(void) {
}

void test_pop_count_empty_bitboard(void) {
  TEST_ASSERT_EQUAL_INT(0, pop_count(bb));
}

void test_pop_count_non_empty_bitboard(void) {
  set_bit(E4, bb);
  set_bit(C2, bb);
  set_bit(F6, bb);

  TEST_ASSERT_EQUAL_INT(3, pop_count(bb));
}

void test_pop_count_full_bitboard(void) {
  bb = ~0ULL;

  TEST_ASSERT_EQUAL_INT(64, pop_count(bb));
}

void test_pop_bit(void) {
  bb = ~0ULL;

  TEST_ASSERT_EQUAL_INT(1, get_bit(E4, bb));
  pop_bit(E4, bb);
  TEST_ASSERT_EQUAL_INT(0, get_bit(E4, bb));

  pop_bit(E4, bb);
  TEST_ASSERT_EQUAL_INT(0, get_bit(E4, bb));

  TEST_ASSERT_EQUAL_INT(1, get_bit(F3, bb));
  pop_bit(F3, bb);
  TEST_ASSERT_EQUAL_INT(0, get_bit(F3, bb));
}

void test_bitscan_fwd(void) {
  set_bit(H8, bb);
  TEST_ASSERT_EQUAL_INT(H8, bitscan_fwd(bb));

  set_bit(G8, bb);
  TEST_ASSERT_EQUAL_INT(G8, bitscan_fwd(bb));

  set_bit(F8, bb);
  TEST_ASSERT_EQUAL_INT(F8, bitscan_fwd(bb));

  set_bit(E8, bb);
  TEST_ASSERT_EQUAL_INT(E8, bitscan_fwd(bb));

  set_bit(D8, bb);
  TEST_ASSERT_EQUAL_INT(D8, bitscan_fwd(bb));

  set_bit(C8, bb);
  TEST_ASSERT_EQUAL_INT(C8, bitscan_fwd(bb));

  set_bit(B8, bb);
  TEST_ASSERT_EQUAL_INT(B8, bitscan_fwd(bb));

  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(A8, bitscan_fwd(bb));

  set_bit(H7, bb);
  TEST_ASSERT_EQUAL_INT(H7, bitscan_fwd(bb));

  set_bit(G7, bb);
  TEST_ASSERT_EQUAL_INT(G7, bitscan_fwd(bb));

  set_bit(F7, bb);
  TEST_ASSERT_EQUAL_INT(F7, bitscan_fwd(bb));

  set_bit(E7, bb);
  TEST_ASSERT_EQUAL_INT(E7, bitscan_fwd(bb));

  set_bit(D7, bb);
  TEST_ASSERT_EQUAL_INT(D7, bitscan_fwd(bb));

  set_bit(C7, bb);
  TEST_ASSERT_EQUAL_INT(C7, bitscan_fwd(bb));

  set_bit(B7, bb);
  TEST_ASSERT_EQUAL_INT(B7, bitscan_fwd(bb));

  set_bit(A7, bb);
  TEST_ASSERT_EQUAL_INT(A7, bitscan_fwd(bb));

  set_bit(H6, bb);
  TEST_ASSERT_EQUAL_INT(H6, bitscan_fwd(bb));

  set_bit(G6, bb);
  TEST_ASSERT_EQUAL_INT(G6, bitscan_fwd(bb));

  set_bit(F6, bb);
  TEST_ASSERT_EQUAL_INT(F6, bitscan_fwd(bb));

  set_bit(E6, bb);
  TEST_ASSERT_EQUAL_INT(E6, bitscan_fwd(bb));

  set_bit(D6, bb);
  TEST_ASSERT_EQUAL_INT(D6, bitscan_fwd(bb));

  set_bit(C6, bb);
  TEST_ASSERT_EQUAL_INT(C6, bitscan_fwd(bb));

  set_bit(B6, bb);
  TEST_ASSERT_EQUAL_INT(B6, bitscan_fwd(bb));

  set_bit(A6, bb);
  TEST_ASSERT_EQUAL_INT(A6, bitscan_fwd(bb));

  set_bit(H5, bb);
  TEST_ASSERT_EQUAL_INT(H5, bitscan_fwd(bb));

  set_bit(G5, bb);
  TEST_ASSERT_EQUAL_INT(G5, bitscan_fwd(bb));

  set_bit(F5, bb);
  TEST_ASSERT_EQUAL_INT(F5, bitscan_fwd(bb));

  set_bit(E5, bb);
  TEST_ASSERT_EQUAL_INT(E5, bitscan_fwd(bb));

  set_bit(D5, bb);
  TEST_ASSERT_EQUAL_INT(D5, bitscan_fwd(bb));

  set_bit(C5, bb);
  TEST_ASSERT_EQUAL_INT(C5, bitscan_fwd(bb));

  set_bit(B5, bb);
  TEST_ASSERT_EQUAL_INT(B5, bitscan_fwd(bb));

  set_bit(A5, bb);
  TEST_ASSERT_EQUAL_INT(A5, bitscan_fwd(bb));

  set_bit(H4, bb);
  TEST_ASSERT_EQUAL_INT(H4, bitscan_fwd(bb));

  set_bit(G4, bb);
  TEST_ASSERT_EQUAL_INT(G4, bitscan_fwd(bb));

  set_bit(F4, bb);
  TEST_ASSERT_EQUAL_INT(F4, bitscan_fwd(bb));

  set_bit(E4, bb);
  TEST_ASSERT_EQUAL_INT(E4, bitscan_fwd(bb));

  set_bit(D4, bb);
  TEST_ASSERT_EQUAL_INT(D4, bitscan_fwd(bb));

  set_bit(C4, bb);
  TEST_ASSERT_EQUAL_INT(C4, bitscan_fwd(bb));

  set_bit(B4, bb);
  TEST_ASSERT_EQUAL_INT(B4, bitscan_fwd(bb));

  set_bit(A4, bb);
  TEST_ASSERT_EQUAL_INT(A4, bitscan_fwd(bb));

  set_bit(H3, bb);
  TEST_ASSERT_EQUAL_INT(H3, bitscan_fwd(bb));

  set_bit(G3, bb);
  TEST_ASSERT_EQUAL_INT(G3, bitscan_fwd(bb));

  set_bit(F3, bb);
  TEST_ASSERT_EQUAL_INT(F3, bitscan_fwd(bb));

  set_bit(E3, bb);
  TEST_ASSERT_EQUAL_INT(E3, bitscan_fwd(bb));

  set_bit(D3, bb);
  TEST_ASSERT_EQUAL_INT(D3, bitscan_fwd(bb));

  set_bit(C3, bb);
  TEST_ASSERT_EQUAL_INT(C3, bitscan_fwd(bb));

  set_bit(B3, bb);
  TEST_ASSERT_EQUAL_INT(B3, bitscan_fwd(bb));

  set_bit(A3, bb);
  TEST_ASSERT_EQUAL_INT(A3, bitscan_fwd(bb));

  set_bit(H2, bb);
  TEST_ASSERT_EQUAL_INT(H2, bitscan_fwd(bb));

  set_bit(G2, bb);
  TEST_ASSERT_EQUAL_INT(G2, bitscan_fwd(bb));

  set_bit(F2, bb);
  TEST_ASSERT_EQUAL_INT(F2, bitscan_fwd(bb));

  set_bit(E2, bb);
  TEST_ASSERT_EQUAL_INT(E2, bitscan_fwd(bb));

  set_bit(D2, bb);
  TEST_ASSERT_EQUAL_INT(D2, bitscan_fwd(bb));

  set_bit(C2, bb);
  TEST_ASSERT_EQUAL_INT(C2, bitscan_fwd(bb));

  set_bit(B2, bb);
  TEST_ASSERT_EQUAL_INT(B2, bitscan_fwd(bb));

  set_bit(A2, bb);
  TEST_ASSERT_EQUAL_INT(A2, bitscan_fwd(bb));

  set_bit(H1, bb);
  TEST_ASSERT_EQUAL_INT(H1, bitscan_fwd(bb));

  set_bit(G1, bb);
  TEST_ASSERT_EQUAL_INT(G1, bitscan_fwd(bb));

  set_bit(F1, bb);
  TEST_ASSERT_EQUAL_INT(F1, bitscan_fwd(bb));

  set_bit(E1, bb);
  TEST_ASSERT_EQUAL_INT(E1, bitscan_fwd(bb));

  set_bit(D1, bb);
  TEST_ASSERT_EQUAL_INT(D1, bitscan_fwd(bb));

  set_bit(C1, bb);
  TEST_ASSERT_EQUAL_INT(C1, bitscan_fwd(bb));

  set_bit(B1, bb);
  TEST_ASSERT_EQUAL_INT(B1, bitscan_fwd(bb));

  set_bit(A1, bb);
  TEST_ASSERT_EQUAL_INT(A1, bitscan_fwd(bb));
}

void test_bitscan_rev(void) {
  set_bit(A1, bb);
  TEST_ASSERT_EQUAL_INT(A1, bitscan_rev(bb));

  set_bit(B1, bb);
  TEST_ASSERT_EQUAL_INT(B1, bitscan_rev(bb));

  set_bit(C1, bb);
  TEST_ASSERT_EQUAL_INT(C1, bitscan_rev(bb));

  set_bit(D1, bb);
  TEST_ASSERT_EQUAL_INT(D1, bitscan_rev(bb));

  set_bit(E1, bb);
  TEST_ASSERT_EQUAL_INT(E1, bitscan_rev(bb));

  set_bit(F1, bb);
  TEST_ASSERT_EQUAL_INT(F1, bitscan_rev(bb));

  set_bit(G1, bb);
  TEST_ASSERT_EQUAL_INT(G1, bitscan_rev(bb));

  set_bit(H1, bb);
  TEST_ASSERT_EQUAL_INT(H1, bitscan_rev(bb));

  set_bit(A2, bb);
  TEST_ASSERT_EQUAL_INT(A2, bitscan_rev(bb));

  set_bit(B2, bb);
  TEST_ASSERT_EQUAL_INT(B2, bitscan_rev(bb));

  set_bit(C2, bb);
  TEST_ASSERT_EQUAL_INT(C2, bitscan_rev(bb));

  set_bit(D2, bb);
  TEST_ASSERT_EQUAL_INT(D2, bitscan_rev(bb));

  set_bit(E2, bb);
  TEST_ASSERT_EQUAL_INT(E2, bitscan_rev(bb));

  set_bit(F2, bb);
  TEST_ASSERT_EQUAL_INT(F2, bitscan_rev(bb));

  set_bit(G2, bb);
  TEST_ASSERT_EQUAL_INT(G2, bitscan_rev(bb));

  set_bit(H2, bb);
  TEST_ASSERT_EQUAL_INT(H2, bitscan_rev(bb));

  set_bit(A3, bb);
  TEST_ASSERT_EQUAL_INT(A3, bitscan_rev(bb));

  set_bit(B3, bb);
  TEST_ASSERT_EQUAL_INT(B3, bitscan_rev(bb));

  set_bit(C3, bb);
  TEST_ASSERT_EQUAL_INT(C3, bitscan_rev(bb));

  set_bit(D3, bb);
  TEST_ASSERT_EQUAL_INT(D3, bitscan_rev(bb));

  set_bit(E3, bb);
  TEST_ASSERT_EQUAL_INT(E3, bitscan_rev(bb));

  set_bit(F3, bb);
  TEST_ASSERT_EQUAL_INT(F3, bitscan_rev(bb));

  set_bit(G3, bb);
  TEST_ASSERT_EQUAL_INT(G3, bitscan_rev(bb));

  set_bit(H3, bb);
  TEST_ASSERT_EQUAL_INT(H3, bitscan_rev(bb));

  set_bit(A4, bb);
  TEST_ASSERT_EQUAL_INT(A4, bitscan_rev(bb));

  set_bit(B4, bb);
  TEST_ASSERT_EQUAL_INT(B4, bitscan_rev(bb));

  set_bit(C4, bb);
  TEST_ASSERT_EQUAL_INT(C4, bitscan_rev(bb));

  set_bit(D4, bb);
  TEST_ASSERT_EQUAL_INT(D4, bitscan_rev(bb));

  set_bit(E4, bb);
  TEST_ASSERT_EQUAL_INT(E4, bitscan_rev(bb));

  set_bit(F4, bb);
  TEST_ASSERT_EQUAL_INT(F4, bitscan_rev(bb));

  set_bit(G4, bb);
  TEST_ASSERT_EQUAL_INT(G4, bitscan_rev(bb));

  set_bit(H4, bb);
  TEST_ASSERT_EQUAL_INT(H4, bitscan_rev(bb));

  set_bit(A5, bb);
  TEST_ASSERT_EQUAL_INT(A5, bitscan_rev(bb));

  set_bit(B5, bb);
  TEST_ASSERT_EQUAL_INT(B5, bitscan_rev(bb));

  set_bit(C5, bb);
  TEST_ASSERT_EQUAL_INT(C5, bitscan_rev(bb));

  set_bit(D5, bb);
  TEST_ASSERT_EQUAL_INT(D5, bitscan_rev(bb));

  set_bit(E5, bb);
  TEST_ASSERT_EQUAL_INT(E5, bitscan_rev(bb));

  set_bit(F5, bb);
  TEST_ASSERT_EQUAL_INT(F5, bitscan_rev(bb));

  set_bit(G5, bb);
  TEST_ASSERT_EQUAL_INT(G5, bitscan_rev(bb));

  set_bit(H5, bb);
  TEST_ASSERT_EQUAL_INT(H5, bitscan_rev(bb));

  set_bit(A6, bb);
  TEST_ASSERT_EQUAL_INT(A6, bitscan_rev(bb));

  set_bit(B6, bb);
  TEST_ASSERT_EQUAL_INT(B6, bitscan_rev(bb));

  set_bit(C6, bb);
  TEST_ASSERT_EQUAL_INT(C6, bitscan_rev(bb));

  set_bit(D6, bb);
  TEST_ASSERT_EQUAL_INT(D6, bitscan_rev(bb));

  set_bit(E6, bb);
  TEST_ASSERT_EQUAL_INT(E6, bitscan_rev(bb));

  set_bit(F6, bb);
  TEST_ASSERT_EQUAL_INT(F6, bitscan_rev(bb));

  set_bit(G6, bb);
  TEST_ASSERT_EQUAL_INT(G6, bitscan_rev(bb));

  set_bit(H6, bb);
  TEST_ASSERT_EQUAL_INT(H6, bitscan_rev(bb));

  set_bit(A7, bb);
  TEST_ASSERT_EQUAL_INT(A7, bitscan_rev(bb));

  set_bit(B7, bb);
  TEST_ASSERT_EQUAL_INT(B7, bitscan_rev(bb));

  set_bit(C7, bb);
  TEST_ASSERT_EQUAL_INT(C7, bitscan_rev(bb));

  set_bit(D7, bb);
  TEST_ASSERT_EQUAL_INT(D7, bitscan_rev(bb));

  set_bit(E7, bb);
  TEST_ASSERT_EQUAL_INT(E7, bitscan_rev(bb));

  set_bit(F7, bb);
  TEST_ASSERT_EQUAL_INT(F7, bitscan_rev(bb));

  set_bit(G7, bb);
  TEST_ASSERT_EQUAL_INT(G7, bitscan_rev(bb));

  set_bit(H7, bb);
  TEST_ASSERT_EQUAL_INT(H7, bitscan_rev(bb));

  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(A8, bitscan_rev(bb));

  set_bit(B8, bb);
  TEST_ASSERT_EQUAL_INT(B8, bitscan_rev(bb));

  set_bit(C8, bb);
  TEST_ASSERT_EQUAL_INT(C8, bitscan_rev(bb));

  set_bit(D8, bb);
  TEST_ASSERT_EQUAL_INT(D8, bitscan_rev(bb));

  set_bit(E8, bb);
  TEST_ASSERT_EQUAL_INT(E8, bitscan_rev(bb));

  set_bit(F8, bb);
  TEST_ASSERT_EQUAL_INT(F8, bitscan_rev(bb));

  set_bit(G8, bb);
  TEST_ASSERT_EQUAL_INT(G8, bitscan_rev(bb));

  set_bit(H8, bb);
  TEST_ASSERT_EQUAL_INT(H8, bitscan_rev(bb));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_pop_count_empty_bitboard);
  RUN_TEST(test_pop_count_non_empty_bitboard);
  RUN_TEST(test_pop_count_full_bitboard);
  RUN_TEST(test_pop_bit);
  RUN_TEST(test_bitscan_fwd);
  RUN_TEST(test_bitscan_rev);
  return UNITY_END();
}
