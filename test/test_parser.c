#include <string.h>
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

  const char error = 'x';
  TEST_ASSERT_EQUAL_INT(NULL_SIDE, parse_side_to_move(error));
}

void test_castling_rights(void) {
  const char* all = "KQkq";     // 001111
  const char* notBq = "KQk";    // 001110
  const char* notBk = "KQq";    // 001101
  const char* white_only = "KQ";        // 001100
  const char* notWq = "Kkq";    // 001011
  const char* kings = "Kk";     // 001010
  const char* bqwk = "Kq";      // 001001
  const char* white_king = "K"; // 001000
  const char* notWk = "Qkq";    // 000111
  const char* wqbk = "Qk";      // 000110
  const char* queens = "Qq";    // 000101
  const char* white_queen = "Q";        // 000100
  const char* black_only = "kq";        // 000011
  const char* black_king = "k"; // 000010
  const char* black_queen = "q";        // 000001
  const char* none = "-";       // 000000

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

void test_parse_string_int(void) {
  char buffer_1[] = { '0', '\0', '\0', '\0', '\0' };
  TEST_ASSERT_EQUAL_INT(0, parse_string_int(buffer_1));

  char buffer_2[] = { '4', '\0', '\0', '\0', '\0' };
  TEST_ASSERT_EQUAL_INT(4, parse_string_int(buffer_2));

  char buffer_3[] = { '1', '0', '\0', '\0', '\0' };
  TEST_ASSERT_EQUAL_INT(10, parse_string_int(buffer_3));

  char buffer_4[] = { '2', '1', '\0', '\0', '\0' };
  TEST_ASSERT_EQUAL_INT(21, parse_string_int(buffer_4));

  char buffer_5[] = { '1', '0', '0', '\0', '\0' };
  TEST_ASSERT_EQUAL_INT(100, parse_string_int(buffer_5));

  char buffer_6[] = { '1', '3', '2', '\0', '\0' };
  TEST_ASSERT_EQUAL_INT(132, parse_string_int(buffer_6));

  char buffer_7[] = { '1', '0', '0', '0', '\0' };
  TEST_ASSERT_EQUAL_INT(1000, parse_string_int(buffer_7));

  char buffer_8[] = { '1', '3', '2', '0', '\0' };
  TEST_ASSERT_EQUAL_INT(1320, parse_string_int(buffer_8));
}

void test_parse_piece_char(void) {
  U64 expected[2][6] = { {0} };
  U64 actual[2][6] = { {0} };
  U64 expected_bb = 0ULL;
  square_t square;
  char piece;

  piece = 'P';
  square = D6;
  set_bit(D6, expected_bb);
  expected[WHITE][P] = expected_bb;

  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'B';
  square = C2;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(C2, expected_bb);
  expected[WHITE][B] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'N';
  square = F4;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(F4, expected_bb);
  expected[WHITE][N] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'Q';
  square = E4;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(E4, expected_bb);
  expected[WHITE][Q] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'K';
  square = H5;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(H5, expected_bb);
  expected[WHITE][K] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'p';
  square = G4;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(G4, expected_bb);
  expected[BLACK][P] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'b';
  square = H8;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(H8, expected_bb);
  expected[BLACK][B] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'n';
  square = C7;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(C7, expected_bb);
  expected[BLACK][N] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'r';
  square = B8;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(B8, expected_bb);
  expected[BLACK][R] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'q';
  square = A5;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(A5, expected_bb);
  expected[BLACK][Q] = expected_bb;
  parse_piece_char(actual, piece, square);
  TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, 12);

  piece = 'k';
  square = A2;
  memset(actual, 0, sizeof(expected));
  memset(expected, 0, sizeof(expected));
  expected_bb = 0ULL;
  set_bit(A2, expected_bb);
  expected[BLACK][K] = expected_bb;
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

void test_parse_game_state(void) {
  board_t board;

  TEST_ASSERT_EQUAL_INT(SUCCESS,
                        parse_fen(&board,
                                  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
  TEST_ASSERT_EQUAL_INT(WHITE, board.side_to_move);
  TEST_ASSERT_EQUAL_STRING("KQkq",
                           decode_castling_rights(board.castle_rights));
  TEST_ASSERT_EQUAL_INT(NULL_SQ, board.ep_square);
  TEST_ASSERT_EQUAL_INT(0, board.half_move_clock);
  TEST_ASSERT_EQUAL_INT(1, board.full_move_num);

  TEST_ASSERT_EQUAL_INT(SUCCESS,
                        parse_fen(&board,
                                  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b Qq e6 34 42"));
  TEST_ASSERT_EQUAL_INT(BLACK, board.side_to_move);
  TEST_ASSERT_EQUAL_STRING(" Q q",
                           decode_castling_rights(board.castle_rights));
  TEST_ASSERT_EQUAL_INT(E6, board.ep_square);
  TEST_ASSERT_EQUAL_INT(34, board.half_move_clock);
  TEST_ASSERT_EQUAL_INT(42, board.full_move_num);

  TEST_ASSERT_EQUAL_INT(SUCCESS,
                        parse_fen(&board,
                                  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b - - 0 1"));
  TEST_ASSERT_EQUAL_INT(BLACK, board.side_to_move);
  TEST_ASSERT_EQUAL_STRING("-   ",
                           decode_castling_rights(board.castle_rights));
  TEST_ASSERT_EQUAL_INT(NULL_SQ, board.ep_square);
  TEST_ASSERT_EQUAL_INT(0, board.half_move_clock);
  TEST_ASSERT_EQUAL_INT(1, board.full_move_num);

  TEST_ASSERT_EQUAL_INT(FAIL,
                        parse_fen(&board,
                                  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR x - - 0 1"));
  TEST_ASSERT_EQUAL_INT(NULL_SIDE, board.side_to_move);

}

void test_parse_position(void) {
  board_t board;
  U64 expected = 0ULL;

  TEST_ASSERT_EQUAL_INT(SUCCESS,
                        parse_fen(&board,
                                  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));

  set_bit(A2, expected);
  set_bit(B2, expected);
  set_bit(C2, expected);
  set_bit(D2, expected);
  set_bit(E2, expected);
  set_bit(F2, expected);
  set_bit(G2, expected);
  set_bit(H2, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[WHITE][P]);

  expected = 0ULL;
  set_bit(A7, expected);
  set_bit(B7, expected);
  set_bit(C7, expected);
  set_bit(D7, expected);
  set_bit(E7, expected);
  set_bit(F7, expected);
  set_bit(G7, expected);
  set_bit(H7, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[BLACK][P]);

  expected = 0ULL;
  set_bit(A1, expected);
  set_bit(H1, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[WHITE][R]);

  expected = 0ULL;
  set_bit(A8, expected);
  set_bit(H8, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[BLACK][R]);

  expected = 0ULL;
  set_bit(B1, expected);
  set_bit(G1, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[WHITE][N]);

  expected = 0ULL;
  set_bit(B8, expected);
  set_bit(G8, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[BLACK][N]);

  expected = 0ULL;
  set_bit(C1, expected);
  set_bit(F1, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[WHITE][B]);

  expected = 0ULL;
  set_bit(C8, expected);
  set_bit(F8, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[BLACK][B]);

  expected = 0ULL;
  set_bit(D1, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[WHITE][Q]);

  expected = 0ULL;
  set_bit(D8, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[BLACK][Q]);

  expected = 0ULL;
  set_bit(E1, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[WHITE][K]);

  expected = 0ULL;
  set_bit(E8, expected);
  TEST_ASSERT_EQUAL_INT(expected, board.pieces[BLACK][K]);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_side_to_move);
  RUN_TEST(test_castling_rights);
  RUN_TEST(test_parse_piece_char);
  RUN_TEST(test_parse_string_int);
  RUN_TEST(test_parse_square);
  RUN_TEST(test_parse_game_state);
  RUN_TEST(test_parse_position);
  return UNITY_END();
}
