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
  print_bitboard(expected);
  print_bitboard(actual);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_is_square_attacked_knight);
  RUN_TEST(test_is_square_attacked_queen);
  return UNITY_END();
}
