#include "../src/board_analytics.h"
#include "../src/bitboard.h"
#include "../src/init.h"
#include "../src/parser.h"
#include "../unity/unity.h"

board_t b;

void setUp(void) {
  empty_board(&b);
  if(!initialized)
    init_all();
}

void tearDown(void) {
}

void test_is_square_attacked_knight(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/8/8/4n3/8/8/8/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }

  set_bit(D3, expected);
  set_bit(F3, expected);
  set_bit(G4, expected);
  set_bit(G6, expected);
  set_bit(D7, expected);
  set_bit(F7, expected);
  set_bit(C6, expected);
  set_bit(C4, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_pawn(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/1p6/p7/4p3/8/7p/8/8 w - - 0 1");

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }
  set_bit(A6, expected);
  set_bit(B5, expected);
  set_bit(C6, expected);
  set_bit(D4, expected);
  set_bit(F4, expected);
  set_bit(G2, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_king(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/8/8/5k2/8/8/8/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }
  set_bit(E6, expected);
  set_bit(E5, expected);
  set_bit(E4, expected);
  set_bit(F6, expected);
  set_bit(F4, expected);
  set_bit(G6, expected);
  set_bit(G5, expected);
  set_bit(G4, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_queen(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/8/8/4nq2/8/8/8/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }

  set_bit(D3, expected);
  set_bit(F3, expected);
  set_bit(G4, expected);
  set_bit(G6, expected);
  set_bit(D7, expected);
  set_bit(F7, expected);
  set_bit(C6, expected);
  set_bit(C4, expected);
  set_bit(F1, expected);
  set_bit(F2, expected);
  set_bit(F4, expected);
  set_bit(E5, expected);
  set_bit(F6, expected);
  set_bit(F7, expected);
  set_bit(F8, expected);
  set_bit(G5, expected);
  set_bit(H5, expected);
  set_bit(G6, expected);
  set_bit(G4, expected);
  set_bit(H7, expected);
  set_bit(H3, expected);
  set_bit(E6, expected);
  set_bit(E4, expected);
  set_bit(D7, expected);
  set_bit(D3, expected);
  set_bit(C8, expected);
  set_bit(C2, expected);
  set_bit(B1, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_queen_occ(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/5P2/8/3P1q2/4P1P1/8/3K1P2/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }

  set_bit(F7, expected);
  set_bit(F6, expected);
  set_bit(F4, expected);
  set_bit(F3, expected);
  set_bit(F2, expected);
  set_bit(D5, expected);
  set_bit(E5, expected);
  set_bit(G5, expected);
  set_bit(H5, expected);
  set_bit(C8, expected);
  set_bit(D7, expected);
  set_bit(E6, expected);
  set_bit(G4, expected);
  set_bit(E4, expected);
  set_bit(G6, expected);
  set_bit(H7, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_rook(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/8/8/5r2/8/8/8/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }

  set_bit(F1, expected);
  set_bit(F2, expected);
  set_bit(F3, expected);
  set_bit(F4, expected);
  set_bit(F6, expected);
  set_bit(F7, expected);
  set_bit(F8, expected);
  set_bit(A5, expected);
  set_bit(B5, expected);
  set_bit(C5, expected);
  set_bit(D5, expected);
  set_bit(E5, expected);
  set_bit(G5, expected);
  set_bit(H5, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_rook_occ(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/5P2/8/3P1r2/4P1P1/8/3K1P2/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }

  set_bit(F7, expected);
  set_bit(F6, expected);
  set_bit(F4, expected);
  set_bit(F3, expected);
  set_bit(F2, expected);
  set_bit(D5, expected);
  set_bit(E5, expected);
  set_bit(G5, expected);
  set_bit(H5, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_bishop(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/8/8/5b2/8/8/8/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }

  set_bit(D3, expected);
  set_bit(G4, expected);
  set_bit(G6, expected);
  set_bit(D7, expected);
  set_bit(G6, expected);
  set_bit(G4, expected);
  set_bit(H7, expected);
  set_bit(H3, expected);
  set_bit(E6, expected);
  set_bit(E4, expected);
  set_bit(D7, expected);
  set_bit(D3, expected);
  set_bit(C8, expected);
  set_bit(C2, expected);
  set_bit(B1, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_is_square_attacked_bishop_occ(void) {
  U64 expected = 0ULL;
  U64 actual = 0ULL;
  parse_fen(&b, "8/5P2/8/3P1b2/4P1P1/8/3K1P2/8 w - - 0 1");
  set_occupancy(&b);

  for(square_t sq = A1; sq < NULL_SQ; sq++) {
    if(is_square_attacked(&b, sq, WHITE))
      set_bit(sq, actual);
  }

  set_bit(C8, expected);
  set_bit(D7, expected);
  set_bit(E6, expected);
  set_bit(G4, expected);
  set_bit(E4, expected);
  set_bit(G6, expected);
  set_bit(H7, expected);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_is_square_attacked_knight);
  RUN_TEST(test_is_square_attacked_pawn);
  RUN_TEST(test_is_square_attacked_king);
  RUN_TEST(test_is_square_attacked_queen);
  RUN_TEST(test_is_square_attacked_queen_occ);
  RUN_TEST(test_is_square_attacked_rook);
  RUN_TEST(test_is_square_attacked_rook_occ);
  RUN_TEST(test_is_square_attacked_bishop);
  RUN_TEST(test_is_square_attacked_bishop_occ);
  return UNITY_END();
}
