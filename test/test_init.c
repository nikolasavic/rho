#include "../src/init.h"
#include "../src/board.h"
#include "../src/bitboard.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_init_rays(void) {
  TEST_ASSERT_EQUAL_INT(0, rays[0][0]);

  init_rays();

  TEST_ASSERT_EQUAL_INT(1157442765139738624ULL, rays[NORTH][E4]);
  TEST_ASSERT_EQUAL_INT(9241421688455823360ULL, rays[NO_EAST][D4]);
  TEST_ASSERT_EQUAL_INT(16252928ULL, rays[EAST][C3]);
  TEST_ASSERT_EQUAL_INT(567382630219904ULL, rays[SO_EAST][A8]);
  TEST_ASSERT_EQUAL_INT(8224ULL, rays[SOUTH][F3]);
  TEST_ASSERT_EQUAL_INT(16416ULL, rays[SO_WEST][H3]);
  TEST_ASSERT_EQUAL_INT(7936ULL, rays[WEST][F2]);
  TEST_ASSERT_EQUAL_INT(16777216ULL, rays[NO_WEST][B3]);
}

void test_king_moves(void) {
  TEST_ASSERT_EQUAL_INT(0, king_moves[0]);

  init_king_moves();

  TEST_ASSERT_EQUAL_INT(241192927232ULL, king_moves[E4]);
}

void test_knight_moves(void) {
  TEST_ASSERT_EQUAL_INT(0, knight_moves[0]);

  init_knight_moves();

  TEST_ASSERT_EQUAL_INT(44272527353856ULL, knight_moves[E4]);
}

void test_pawn_moves() {
  TEST_ASSERT_EQUAL_INT(0, pawn_moves[0][0]);

  init_pawn_moves();

  TEST_ASSERT_EQUAL_INT(269484032ULL, pawn_moves[WHITE][E2]);
  TEST_ASSERT_EQUAL_INT(17592186044416ULL, pawn_moves[WHITE][E5]);
  TEST_ASSERT_EQUAL_INT(16ULL, pawn_moves[BLACK][E2]);
  TEST_ASSERT_EQUAL_INT(141287244169216ULL, pawn_moves[BLACK][H7]);
}

void test_pawn_attacks() {
  TEST_ASSERT_EQUAL_INT(0, pawn_attacks[0][0]);

  init_pawn_attacks();

  TEST_ASSERT_EQUAL_INT(0ULL, pawn_attacks[WHITE][C8]);
  TEST_ASSERT_EQUAL_INT(21474836480ULL, pawn_attacks[WHITE][B4]);
  TEST_ASSERT_EQUAL_INT(1073741824ULL, pawn_attacks[WHITE][H3]);
  TEST_ASSERT_EQUAL_INT(0ULL, pawn_attacks[BLACK][A1]);
  TEST_ASSERT_EQUAL_INT(20ULL, pawn_attacks[BLACK][D2]);
  TEST_ASSERT_EQUAL_INT(2684354560ULL, pawn_attacks[BLACK][G5]);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_init_rays);
  RUN_TEST(test_king_moves);
  RUN_TEST(test_knight_moves);
  RUN_TEST(test_pawn_moves);
  RUN_TEST(test_pawn_attacks);
  return UNITY_END();
}
