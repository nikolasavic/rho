#include "../src/board.h"
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

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_square_names);
  RUN_TEST(test_empty_board);
  RUN_TEST(test_validate_board);
  RUN_TEST(test_empty_board_is_invalid);
  RUN_TEST(test_square_to_rank);
  RUN_TEST(test_square_to_file);
  return UNITY_END();
}
