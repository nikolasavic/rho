#include "../src/board.h"
#include "../src/parser.h"
#include "../unity/unity.h"

board_t b;

void setUp(void) {
  empty_board(&b);
}

void tearDown(void) {
}

void test_square_names(void) {
  TEST_ASSERT_EQUAL_STRING("a8", square_name[A8]);
  TEST_ASSERT_EQUAL_STRING("b8", square_name[B8]);
  TEST_ASSERT_EQUAL_STRING("c8", square_name[C8]);
  TEST_ASSERT_EQUAL_STRING("d8", square_name[D8]);
  TEST_ASSERT_EQUAL_STRING("e8", square_name[E8]);
  TEST_ASSERT_EQUAL_STRING("f8", square_name[F8]);
  TEST_ASSERT_EQUAL_STRING("g8", square_name[G8]);
  TEST_ASSERT_EQUAL_STRING("h8", square_name[H8]);
  TEST_ASSERT_EQUAL_STRING("a7", square_name[A7]);
  TEST_ASSERT_EQUAL_STRING("b7", square_name[B7]);
  TEST_ASSERT_EQUAL_STRING("c7", square_name[C7]);
  TEST_ASSERT_EQUAL_STRING("d7", square_name[D7]);
  TEST_ASSERT_EQUAL_STRING("e7", square_name[E7]);
  TEST_ASSERT_EQUAL_STRING("f7", square_name[F7]);
  TEST_ASSERT_EQUAL_STRING("g7", square_name[G7]);
  TEST_ASSERT_EQUAL_STRING("h7", square_name[H7]);
  TEST_ASSERT_EQUAL_STRING("a6", square_name[A6]);
  TEST_ASSERT_EQUAL_STRING("b6", square_name[B6]);
  TEST_ASSERT_EQUAL_STRING("c6", square_name[C6]);
  TEST_ASSERT_EQUAL_STRING("d6", square_name[D6]);
  TEST_ASSERT_EQUAL_STRING("e6", square_name[E6]);
  TEST_ASSERT_EQUAL_STRING("f6", square_name[F6]);
  TEST_ASSERT_EQUAL_STRING("g6", square_name[G6]);
  TEST_ASSERT_EQUAL_STRING("h6", square_name[H6]);
  TEST_ASSERT_EQUAL_STRING("a5", square_name[A5]);
  TEST_ASSERT_EQUAL_STRING("b5", square_name[B5]);
  TEST_ASSERT_EQUAL_STRING("c5", square_name[C5]);
  TEST_ASSERT_EQUAL_STRING("d5", square_name[D5]);
  TEST_ASSERT_EQUAL_STRING("e5", square_name[E5]);
  TEST_ASSERT_EQUAL_STRING("f5", square_name[F5]);
  TEST_ASSERT_EQUAL_STRING("g5", square_name[G5]);
  TEST_ASSERT_EQUAL_STRING("h5", square_name[H5]);
  TEST_ASSERT_EQUAL_STRING("a4", square_name[A4]);
  TEST_ASSERT_EQUAL_STRING("b4", square_name[B4]);
  TEST_ASSERT_EQUAL_STRING("c4", square_name[C4]);
  TEST_ASSERT_EQUAL_STRING("d4", square_name[D4]);
  TEST_ASSERT_EQUAL_STRING("e4", square_name[E4]);
  TEST_ASSERT_EQUAL_STRING("f4", square_name[F4]);
  TEST_ASSERT_EQUAL_STRING("g4", square_name[G4]);
  TEST_ASSERT_EQUAL_STRING("h4", square_name[H4]);
  TEST_ASSERT_EQUAL_STRING("a3", square_name[A3]);
  TEST_ASSERT_EQUAL_STRING("b3", square_name[B3]);
  TEST_ASSERT_EQUAL_STRING("c3", square_name[C3]);
  TEST_ASSERT_EQUAL_STRING("d3", square_name[D3]);
  TEST_ASSERT_EQUAL_STRING("e3", square_name[E3]);
  TEST_ASSERT_EQUAL_STRING("f3", square_name[F3]);
  TEST_ASSERT_EQUAL_STRING("g3", square_name[G3]);
  TEST_ASSERT_EQUAL_STRING("h3", square_name[H3]);
  TEST_ASSERT_EQUAL_STRING("a2", square_name[A2]);
  TEST_ASSERT_EQUAL_STRING("b2", square_name[B2]);
  TEST_ASSERT_EQUAL_STRING("c2", square_name[C2]);
  TEST_ASSERT_EQUAL_STRING("d2", square_name[D2]);
  TEST_ASSERT_EQUAL_STRING("e2", square_name[E2]);
  TEST_ASSERT_EQUAL_STRING("f2", square_name[F2]);
  TEST_ASSERT_EQUAL_STRING("g2", square_name[G2]);
  TEST_ASSERT_EQUAL_STRING("h2", square_name[H2]);
  TEST_ASSERT_EQUAL_STRING("a1", square_name[A1]);
  TEST_ASSERT_EQUAL_STRING("b1", square_name[B1]);
  TEST_ASSERT_EQUAL_STRING("c1", square_name[C1]);
  TEST_ASSERT_EQUAL_STRING("d1", square_name[D1]);
  TEST_ASSERT_EQUAL_STRING("e1", square_name[E1]);
  TEST_ASSERT_EQUAL_STRING("f1", square_name[F1]);
  TEST_ASSERT_EQUAL_STRING("g1", square_name[G1]);
  TEST_ASSERT_EQUAL_STRING("h1", square_name[H1]);
}

void test_empty_board(void) {
  TEST_ASSERT_EQUAL_INT(NULL_SIDE, b.side_to_move);
  TEST_ASSERT_EQUAL_INT(NULL_SQ, b.ep_square);
  TEST_ASSERT_EQUAL_INT(0, b.half_move_clock);
  TEST_ASSERT_EQUAL_INT(0, b.full_move_num);
  TEST_ASSERT_EQUAL_INT(16, b.castle_rights);
  TEST_ASSERT_EQUAL_STRING("null", decode_castling_rights(b.castle_rights));

  for(int side = 0; side < 2; side++) {
    for(int piece = 0; piece < 6; piece++) {
      TEST_ASSERT_EQUAL_INT(0, b.pieces[side][piece]);
    }
  }

  TEST_ASSERT_EQUAL_INT(0, b.occupancy[WHITE]);
  TEST_ASSERT_EQUAL_INT(0, b.occupancy[BLACK]);
  TEST_ASSERT_EQUAL_INT(0, b.occupancy[BOTH]);
}

void test_validate_board(void) {
  b.pieces[BLACK][P] = 268959744ULL;
  b.pieces[BLACK][N] = 137438953472ULL;
  b.pieces[BLACK][B] = 512ULL;
  b.pieces[BLACK][R] = 129ULL;
  b.pieces[BLACK][Q] = 2048ULL;
  b.pieces[BLACK][K] = 64ULL;
  b.pieces[WHITE][P] = 4501125726208ULL;
  b.pieces[WHITE][N] = 35184372088832ULL;
  b.pieces[WHITE][B] = 70385924046848ULL;
  b.pieces[WHITE][R] = 9295429630892703744ULL;
  b.pieces[WHITE][Q] = 576460752303423488ULL;
  b.pieces[WHITE][K] = 18014398509481984ULL;
  b.ep_square = 23;
  b.half_move_clock = 7;
  b.full_move_num = 15;
  b.castle_rights = 2;
  b.side_to_move = 0;

  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_board(&b, SILENT));
}

void test_empty_board_is_invalid(void) {
  TEST_ASSERT_EQUAL_INT(FAIL, validate_board(&b, SILENT));
}

void test_square_to_rank(void) {
  TEST_ASSERT_EQUAL_INT(0, square_to_rank[A1]);
  TEST_ASSERT_EQUAL_INT(1, square_to_rank[C2]);
  TEST_ASSERT_EQUAL_INT(2, square_to_rank[D3]);
  TEST_ASSERT_EQUAL_INT(3, square_to_rank[E4]);
  TEST_ASSERT_EQUAL_INT(4, square_to_rank[G5]);
  TEST_ASSERT_EQUAL_INT(5, square_to_rank[B6]);
  TEST_ASSERT_EQUAL_INT(6, square_to_rank[H7]);
  TEST_ASSERT_EQUAL_INT(7, square_to_rank[F8]);
}

void test_square_to_file(void) {
  TEST_ASSERT_EQUAL_INT(0, square_to_file[A2]);
  TEST_ASSERT_EQUAL_INT(1, square_to_file[B5]);
  TEST_ASSERT_EQUAL_INT(2, square_to_file[C1]);
  TEST_ASSERT_EQUAL_INT(3, square_to_file[D6]);
  TEST_ASSERT_EQUAL_INT(4, square_to_file[E4]);
  TEST_ASSERT_EQUAL_INT(5, square_to_file[F7]);
  TEST_ASSERT_EQUAL_INT(6, square_to_file[G3]);
  TEST_ASSERT_EQUAL_INT(7, square_to_file[H8]);
}

void test_square_to_bitboard(void) {
  U64 bb;

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A8], bb);

  bb = 0ULL;
  set_bit(B8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B8], bb);

  bb = 0ULL;
  set_bit(C8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C8], bb);

  bb = 0ULL;
  set_bit(D8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D8], bb);

  bb = 0ULL;
  set_bit(E8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E8], bb);

  bb = 0ULL;
  set_bit(F8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F8], bb);

  bb = 0ULL;
  set_bit(G8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G8], bb);

  bb = 0ULL;
  set_bit(H8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H8], bb);

  bb = 0ULL;
  set_bit(A7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A7], bb);

  bb = 0ULL;
  set_bit(B7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B7], bb);

  bb = 0ULL;
  set_bit(C7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C7], bb);

  bb = 0ULL;
  set_bit(D7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D7], bb);

  bb = 0ULL;
  set_bit(E7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E7], bb);

  bb = 0ULL;
  set_bit(F7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F7], bb);

  bb = 0ULL;
  set_bit(G7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G7], bb);

  bb = 0ULL;
  set_bit(H7, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H7], bb);

  bb = 0ULL;
  set_bit(A6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A6], bb);

  bb = 0ULL;
  set_bit(B6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B6], bb);

  bb = 0ULL;
  set_bit(C6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C6], bb);

  bb = 0ULL;
  set_bit(D6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D6], bb);

  bb = 0ULL;
  set_bit(E6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E6], bb);

  bb = 0ULL;
  set_bit(F6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F6], bb);

  bb = 0ULL;
  set_bit(G6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G6], bb);

  bb = 0ULL;
  set_bit(H6, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H6], bb);

  bb = 0ULL;
  set_bit(A5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A5], bb);

  bb = 0ULL;
  set_bit(B5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B5], bb);

  bb = 0ULL;
  set_bit(C5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C5], bb);

  bb = 0ULL;
  set_bit(D5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D5], bb);

  bb = 0ULL;
  set_bit(E5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E5], bb);

  bb = 0ULL;
  set_bit(F5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F5], bb);

  bb = 0ULL;
  set_bit(G5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G5], bb);

  bb = 0ULL;
  set_bit(H5, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H5], bb);

  bb = 0ULL;
  set_bit(A4, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A4], bb);

  bb = 0ULL;
  set_bit(B4, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B4], bb);

  bb = 0ULL;
  set_bit(C4, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C4], bb);

  bb = 0ULL;
  set_bit(D4, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D4], bb);

  // FIXME start here
  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E4], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F4], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G4], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H4], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H3], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H2], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[A1], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[B1], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[C1], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[D1], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[E1], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[F1], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[G1], bb);

  bb = 0ULL;
  set_bit(A8, bb);
  TEST_ASSERT_EQUAL_INT(square_to_bitboard[H1], bb);
}

void test_set_occupancy(void) {
  U64 expected = 0ULL;
  parse_fen(&b, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

  TEST_ASSERT_EQUAL_INT(0, b.occupancy[WHITE]);
  TEST_ASSERT_EQUAL_INT(0, b.occupancy[BLACK]);
  TEST_ASSERT_EQUAL_INT(0, b.occupancy[BOTH]);

  set_occupancy(&b);

  set_bit(A1, expected);
  set_bit(B1, expected);
  set_bit(C1, expected);
  set_bit(D1, expected);
  set_bit(E1, expected);
  set_bit(F1, expected);
  set_bit(G1, expected);
  set_bit(H1, expected);
  set_bit(A2, expected);
  set_bit(B2, expected);
  set_bit(C2, expected);
  set_bit(D2, expected);
  set_bit(E2, expected);
  set_bit(F2, expected);
  set_bit(G2, expected);
  set_bit(H2, expected);
  TEST_ASSERT_EQUAL_INT(expected, b.occupancy[WHITE]);

  set_bit(A7, expected);
  set_bit(B7, expected);
  set_bit(C7, expected);
  set_bit(D7, expected);
  set_bit(E7, expected);
  set_bit(F7, expected);
  set_bit(G7, expected);
  set_bit(H7, expected);
  set_bit(A8, expected);
  set_bit(B8, expected);
  set_bit(C8, expected);
  set_bit(D8, expected);
  set_bit(E8, expected);
  set_bit(F8, expected);
  set_bit(G8, expected);
  set_bit(H8, expected);
  TEST_ASSERT_EQUAL_INT(expected, b.occupancy[BOTH]);

  expected = 0ULL;
  set_bit(A7, expected);
  set_bit(B7, expected);
  set_bit(C7, expected);
  set_bit(D7, expected);
  set_bit(E7, expected);
  set_bit(F7, expected);
  set_bit(G7, expected);
  set_bit(H7, expected);
  set_bit(A8, expected);
  set_bit(B8, expected);
  set_bit(C8, expected);
  set_bit(D8, expected);
  set_bit(E8, expected);
  set_bit(F8, expected);
  set_bit(G8, expected);
  set_bit(H8, expected);
  TEST_ASSERT_EQUAL_INT(expected, b.occupancy[BLACK]);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_square_names);
  RUN_TEST(test_empty_board);
  RUN_TEST(test_validate_board);
  RUN_TEST(test_empty_board_is_invalid);
  RUN_TEST(test_square_to_rank);
  RUN_TEST(test_square_to_file);
  RUN_TEST(test_set_occupancy);
  return UNITY_END();
}
