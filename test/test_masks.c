#include "../src/masks.h"
#include "../src/init.h"
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
  set_bit(E5, expected);
  TEST_ASSERT_EQUAL_INT(expected, pawn_motion_mask(E4, WHITE));

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

void test_king_attack_mask(void) {
  U64 expected;

  expected = 0ULL;
  set_bit(E3, expected);
  set_bit(F3, expected);
  set_bit(G3, expected);
  set_bit(E2, expected);
  set_bit(G2, expected);
  set_bit(E1, expected);
  set_bit(F1, expected);
  set_bit(G1, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(F2));

  expected = 0ULL;
  set_bit(D2, expected);
  set_bit(E2, expected);
  set_bit(F2, expected);
  set_bit(D1, expected);
  set_bit(F1, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(E1));

  expected = 0ULL;
  set_bit(H2, expected);
  set_bit(G2, expected);
  set_bit(G1, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(H1));

  expected = 0ULL;
  set_bit(H6, expected);
  set_bit(G6, expected);
  set_bit(G5, expected);
  set_bit(G4, expected);
  set_bit(H4, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(H5));

  expected = 0ULL;
  set_bit(H7, expected);
  set_bit(G8, expected);
  set_bit(G7, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(H8));

  expected = 0ULL;
  set_bit(C7, expected);
  set_bit(B8, expected);
  set_bit(B7, expected);
  set_bit(D8, expected);
  set_bit(D7, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(C8));

  expected = 0ULL;
  set_bit(A7, expected);
  set_bit(B8, expected);
  set_bit(B7, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(A8));

  expected = 0ULL;
  set_bit(A4, expected);
  set_bit(B4, expected);
  set_bit(B3, expected);
  set_bit(B2, expected);
  set_bit(A2, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(A3));

  expected = 0ULL;
  set_bit(A2, expected);
  set_bit(B2, expected);
  set_bit(B1, expected);
  TEST_ASSERT_EQUAL_INT(expected, king_attack_mask(A1));
}

void test_knight_attack_mask(void) {
  U64 expected;

  expected = 0ULL;
  set_bit(A2, expected);
  set_bit(A4, expected);
  set_bit(B1, expected);
  set_bit(B5, expected);
  set_bit(D5, expected);
  set_bit(D1, expected);
  set_bit(E2, expected);
  set_bit(E4, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(C3));

  expected = 0ULL;
  set_bit(A1, expected);
  set_bit(A3, expected);
  set_bit(B4, expected);
  set_bit(D4, expected);
  set_bit(E1, expected);
  set_bit(E3, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(C2));

  expected = 0ULL;
  set_bit(A2, expected);
  set_bit(B3, expected);
  set_bit(D3, expected);
  set_bit(E2, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(C1));

  expected = 0ULL;
  set_bit(A3, expected);
  set_bit(C3, expected);
  set_bit(D2, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(B1));

  expected = 0ULL;
  set_bit(A4, expected);
  set_bit(C4, expected);
  set_bit(D3, expected);
  set_bit(D1, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(B2));

  expected = 0ULL;
  set_bit(B3, expected);
  set_bit(C2, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(A1));

  expected = 0ULL;
  set_bit(B4, expected);
  set_bit(C3, expected);
  set_bit(C1, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(A2));

  expected = 0ULL;
  set_bit(B5, expected);
  set_bit(B1, expected);
  set_bit(C4, expected);
  set_bit(C2, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(A3));

  expected = 0ULL;
  set_bit(B5, expected);
  set_bit(C8, expected);
  set_bit(C6, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(A7));

  expected = 0ULL;
  set_bit(B6, expected);
  set_bit(C7, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(A8));

  expected = 0ULL;
  set_bit(A6, expected);
  set_bit(C6, expected);
  set_bit(D7, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(B8));

  expected = 0ULL;
  set_bit(F6, expected);
  set_bit(G7, expected);
  set_bit(C7, expected);
  set_bit(D6, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(E8));

  expected = 0ULL;
  set_bit(C8, expected);
  set_bit(G8, expected);
  set_bit(F5, expected);
  set_bit(G6, expected);
  set_bit(C6, expected);
  set_bit(D5, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(E7));

  expected = 0ULL;
  set_bit(E8, expected);
  set_bit(E6, expected);
  set_bit(F5, expected);
  set_bit(H5, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(G7));

  expected = 0ULL;
  set_bit(E7, expected);
  set_bit(F6, expected);
  set_bit(H6, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(G8));

  expected = 0ULL;
  set_bit(F7, expected);
  set_bit(G6, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(H8));

  expected = 0ULL;
  set_bit(F8, expected);
  set_bit(F6, expected);
  set_bit(G5, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(H7));

  expected = 0ULL;
  set_bit(G8, expected);
  set_bit(F7, expected);
  set_bit(F5, expected);
  set_bit(G4, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(H6));

  expected = 0ULL;
  set_bit(G4, expected);
  set_bit(F3, expected);
  set_bit(F1, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(H2));

  expected = 0ULL;
  set_bit(F2, expected);
  set_bit(G3, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(H1));

  expected = 0ULL;
  set_bit(H3, expected);
  set_bit(F3, expected);
  set_bit(E2, expected);
  TEST_ASSERT_EQUAL_INT(expected, knight_attack_mask(G1));
}

void test_rook_attack_mask(void) {
  init_rays();
  U64 expected, blockers;

  blockers = 0ULL;
  set_bit(B3, blockers);
  set_bit(C6, blockers);
  set_bit(C2, blockers);
  set_bit(G3, blockers);
  expected = 0ULL;
  set_bit(B3, expected);
  set_bit(D3, expected);
  set_bit(E3, expected);
  set_bit(F3, expected);
  set_bit(G3, expected);
  set_bit(C2, expected);
  set_bit(C4, expected);
  set_bit(C5, expected);
  set_bit(C6, expected);
  TEST_ASSERT_EQUAL_INT(expected, rook_attack_mask(C3, blockers));

  blockers = 0ULL;
  set_bit(F8, blockers);
  set_bit(G7, blockers);
  set_bit(F2, blockers);
  set_bit(D7, blockers);
  expected = 0ULL;
  set_bit(F8, expected);
  set_bit(F6, expected);
  set_bit(F5, expected);
  set_bit(F4, expected);
  set_bit(F3, expected);
  set_bit(F2, expected);
  set_bit(G7, expected);
  set_bit(E7, expected);
  set_bit(D7, expected);
  TEST_ASSERT_EQUAL_INT(expected, rook_attack_mask(F7, blockers));

  blockers = 0ULL;
  expected = 0ULL;
  set_bit(A8, expected);
  set_bit(A7, expected);
  set_bit(A6, expected);
  set_bit(A5, expected);
  set_bit(A4, expected);
  set_bit(A3, expected);
  set_bit(A2, expected);
  set_bit(B1, expected);
  set_bit(C1, expected);
  set_bit(D1, expected);
  set_bit(E1, expected);
  set_bit(F1, expected);
  set_bit(G1, expected);
  set_bit(H1, expected);
  TEST_ASSERT_EQUAL_INT(expected, rook_attack_mask(A1, blockers));
}

void test_ray_north(void) {
  U64 expected = 0ULL;

  expected = 72057594037927936ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north(A7));

  expected = 144680345676153344ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north(B1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north(D8));

  expected = 1157442765139738624ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north(E4));

  expected = 9259542123265392640ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north(H3));
}

void test_ray_north_east() {
  U64 expected = 0ULL;

  expected = 144115188075855872ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(A7));

  expected = 4620710844295020544ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(B3));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(A8));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(D8));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(H2));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(H8));

  expected = 141012903133184ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(E3));

  expected = 144115188075855872ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_east(A7));
}

void test_ray_east() {
  U64 expected = 0ULL;

  expected = 69805794224242688ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_east(C7));

  expected = 17293822569102704640ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_east(D8));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_east(H6));

  expected = 32768ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_east(G2));

  expected = 192ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_east(F1));
}

void test_ray_south_east() {
  U64 expected = 0ULL;

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_east(A1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_east(H1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_east(D1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_east(H8));

  expected = 2216338399296ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_east(A7));

  expected = 277025390592ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_east(F6));
}

void test_ray_south() {
  U64 expected = 0ULL;

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south(A1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south(C1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south(H1));

  expected = 275955859520ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south(G6));
}

void test_ray_south_west() {
  U64 expected = 0ULL;

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_west(A4));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_west(A1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_west(F1));

  expected = 34426978560ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_west(E6));

  expected = 1ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_west(B2));

  expected = 268960770ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_south_west(F5));
}

void test_ray_west() {
  U64 expected = 0ULL;

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_west(A4));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_west(A1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_west(A8));

  expected = 16492674416640ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_west(E6));

  expected = 196608ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_west(C3));
}

void test_ray_north_west() {
  U64 expected = 0ULL;

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_west(C8));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_west(A5));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_west(A1));

  expected = 0ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_west(A8));

  expected = 580964351930793984ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_west(F6));

  expected = 1108168671232ULL;
  TEST_ASSERT_EQUAL_INT(expected, ray_north_west(D3));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_pawn_attack_mask);
  RUN_TEST(test_pawn_motion_mask);
  RUN_TEST(test_king_attack_mask);
  RUN_TEST(test_knight_attack_mask);
  RUN_TEST(test_rook_attack_mask);
  RUN_TEST(test_ray_north);
  RUN_TEST(test_ray_north_east);
  RUN_TEST(test_ray_east);
  RUN_TEST(test_ray_south_east);
  RUN_TEST(test_ray_south);
  RUN_TEST(test_ray_south_west);
  RUN_TEST(test_ray_west);
  RUN_TEST(test_ray_north_west);
  return UNITY_END();
}
