#include <string.h>
#include "../src/defs.h"
#include "../src/parser.h"
#include "../src/board.h"
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

void test_parse_string_int(void){
  char buffer_1[] = { '0', '\0', '\0', '\0', '\0'};
  TEST_ASSERT_EQUAL_INT(0, parse_string_int(buffer_1));

  char buffer_2[] = { '4', '\0', '\0', '\0', '\0'};
  TEST_ASSERT_EQUAL_INT(4, parse_string_int(buffer_2));

  char buffer_3[] = { '1', '0', '\0', '\0', '\0'};
  TEST_ASSERT_EQUAL_INT(10, parse_string_int(buffer_3));

  char buffer_4[] = { '2', '1', '\0', '\0', '\0'};
  TEST_ASSERT_EQUAL_INT(21, parse_string_int(buffer_4));

  char buffer_5[] = { '1', '0', '0', '\0', '\0'};
  TEST_ASSERT_EQUAL_INT(100, parse_string_int(buffer_5));

  char buffer_6[] = { '1', '3', '2', '\0', '\0'};
  TEST_ASSERT_EQUAL_INT(132, parse_string_int(buffer_6));

  char buffer_7[] = { '1', '0', '0', '0', '\0'};
  TEST_ASSERT_EQUAL_INT(1000, parse_string_int(buffer_7));

  char buffer_8[] = { '1', '3', '2', '0', '\0'};
  TEST_ASSERT_EQUAL_INT(1320, parse_string_int(buffer_8));
}

void test_parse_piece_char(void) {
  U64 expected[2][6] = { {0} };
  U64 actual[2][6] = { {0} };
  square_t square;
  char piece;

  piece = 'P';
  square = D6;
  expected[WHITE][P] = 524288ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'B';
  square = C2;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[WHITE][B] = 1125899906842624ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'N';
  square = F4;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[WHITE][N] = 137438953472ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'Q';
  square = E4;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[WHITE][Q] = 68719476736ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'K';
  square = H5;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[WHITE][K] = 2147483648ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'p';
  square = G4;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[BLACK][P] = 274877906944ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'b';
  square = H8;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[BLACK][B] = 128ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'n';
  square = C7;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[BLACK][N] = 1024ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'r';
  square = B8;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[BLACK][R] = 2ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'q';
  square = A5;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[BLACK][Q] = 16777216ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'k';
  square = A2;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected[BLACK][K] = 281474976710656ULL;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);
}

void test_parse_square(void) {
  char* square;
  square = "a8";
  TEST_ASSERT_EQUAL_INT(A8, parse_square(square));

  square = "b2";
  TEST_ASSERT_EQUAL_INT(B2, parse_square(square));

  square = "c4";
  TEST_ASSERT_EQUAL_INT(C4, parse_square(square));

  square = "g3";
  TEST_ASSERT_EQUAL_INT(G3, parse_square(square));

  square = "e6";
  TEST_ASSERT_EQUAL_INT(E6, parse_square(square));

  square = "d5";
  TEST_ASSERT_EQUAL_INT(D5, parse_square(square));

  square = "f7";
  TEST_ASSERT_EQUAL_INT(F7, parse_square(square));

  square = "h1";
  TEST_ASSERT_EQUAL_INT(H1, parse_square(square));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_side_to_move);
  RUN_TEST(test_castling_rights);
  RUN_TEST(test_parse_piece_char);
  RUN_TEST(test_parse_string_int);
  RUN_TEST(test_parse_square);
  return UNITY_END();
}
