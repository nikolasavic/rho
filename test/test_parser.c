#include "../src/defs.h"
#include "../src/parser.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_side_to_move(void) {
  const char black_side = 'b';
  TEST_ASSERT_EQUAL_INT(BLACK, parse_side_to_move(black_side));

  const char white_side = 'w';
  TEST_ASSERT_EQUAL_INT(WHITE, parse_side_to_move(white_side));
}

void test_castling_rights(void) {
  const char *all = "KQkq";             // 001111
  const char *notBq = "KQk";            // 001110
  const char *notBk = "KQq";            // 001101
  const char *white_only = "KQ";        // 001100
  const char *notWq = "Kkq";            // 001011
  const char *kings = "Kk";             // 001010
  const char *bqwk = "Kq";              // 001001
  const char *white_king = "K";         // 001000
  const char *notWk = "Qkq";            // 000111
  const char *wqbk = "Qk";              // 000110
  const char *queens = "Qq";            // 000101
  const char *white_queen = "Q";        // 000100
  const char *black_only = "kq";        // 000011
  const char *black_king = "k";         // 000010
  const char *black_queen = "q";        // 000001
  const char *none = "-";               // 000000

  TEST_ASSERT_EQUAL_CHAR(0xf, parse_castling_rights(all));
  TEST_ASSERT_EQUAL_CHAR(0xe, parse_castling_rights(notBq));
  TEST_ASSERT_EQUAL_CHAR(0xd, parse_castling_rights(notBk));
  TEST_ASSERT_EQUAL_CHAR(0xc, parse_castling_rights(white_only));
  TEST_ASSERT_EQUAL_CHAR(0xb, parse_castling_rights(notWq));
  TEST_ASSERT_EQUAL_CHAR(0xa, parse_castling_rights(kings));
  TEST_ASSERT_EQUAL_CHAR(0x9, parse_castling_rights(bqwk));
  TEST_ASSERT_EQUAL_CHAR(0x8, parse_castling_rights(white_king));
  TEST_ASSERT_EQUAL_CHAR(0x5, parse_castling_rights(queens));
  TEST_ASSERT_EQUAL_CHAR(0x4, parse_castling_rights(white_queen));
  TEST_ASSERT_EQUAL_CHAR(0x3, parse_castling_rights(black_only));
  TEST_ASSERT_EQUAL_CHAR(0x2, parse_castling_rights(black_king));
  TEST_ASSERT_EQUAL_CHAR(0x1, parse_castling_rights(black_queen));
  TEST_ASSERT_EQUAL_CHAR(0x0, parse_castling_rights(none));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_side_to_move);
  RUN_TEST(test_castling_rights);
  return UNITY_END();
}
