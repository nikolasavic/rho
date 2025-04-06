#include <string.h>
#include "helpers.h"
#include "../src/init.h"
#include "../src/board.h"
#include "../src/move.h"
#include "../src/move_list.h"
#include "../src/move_gen.h"
#include "../src/parser.h"
#include "../unity/unity.h"

board_t board;
move_list_t ml;

void setUp(void) {
  empty_board(&board);
  empty_move_list(&ml);
  init_all();
}

void tearDown(void) {
}

void test_generate_knight_moves_white(void) {
  parse_fen(&board,
            "r1bqkbnr/ppp2ppp/2n5/3pp3/4P3/2N2N2/PPPP1PPP/R1BQKB1R w KQkq - 2 3");
  set_occupancy(&board);

  int expected_move_len = 5;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {C3, B1, 0, 1, 0, 0, 0, 0, 0},
    {C3, A4, 0, 1, 0, 0, 0, 0, 0},
    {C3, B5, 0, 1, 0, 0, 0, 0, 0},
    {C3, E2, 0, 1, 0, 0, 0, 0, 0},
    {C3, D5, 0, 0, 0, 1, 0, 0, 0},
  };

  int not_expected_move_len = 3;
  move_t not_expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {C3, E4, 0, 0, 0, 1, 0, 0, 0},
    {C3, D1, 0, 0, 0, 1, 0, 0, 0},
    {C3, A2, 0, 0, 0, 1, 0, 0, 0},
  };

  generate_moves(&ml, &board, WHITE);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
  for(int i = 0; i < not_expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(false,
                          is_move_in_list(&ml, &not_expected_moves[i]));
  }
}

void test_generate_knight_moves_black(void) {
  parse_fen(&board, "5k2/8/4np2/4p1n1/5P2/6P1/6K1/4R3 b - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 6;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {E6, D8, 0, 1, 0, 0, 0, 0, 0},
    {E6, C7, 0, 1, 0, 0, 0, 0, 0},
    {E6, C5, 0, 1, 0, 0, 0, 0, 0},
    {E6, D4, 0, 1, 0, 0, 0, 0, 0},
    {E6, F4, 0, 0, 0, 1, 0, 0, 0},
    {E6, G7, 0, 1, 0, 0, 0, 0, 0},
  };

  int not_expected_move_len = 2;
  move_t not_expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {E6, G5, 0, 1, 0, 0, 0, 0, 0},
    {E6, F8, 0, 1, 0, 0, 0, 0, 0},
  };

  generate_moves(&ml, &board, BLACK);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
  for(int i = 0; i < not_expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(false,
                          is_move_in_list(&ml, &not_expected_moves[i]));
  }
}

void test_generate_king_moves_white(void) {
  parse_fen(&board, "8/1k6/8/1Pp5/2K5/8/8/8 w - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 7;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {C4, C5, 0, 0, 0, 1, 0, 0, 0},
    {C4, D5, 0, 1, 0, 0, 0, 0, 0},
    {C4, D4, 0, 1, 0, 0, 0, 0, 0},
    {C4, D3, 0, 1, 0, 0, 0, 0, 0},
    {C4, C3, 0, 1, 0, 0, 0, 0, 0},
    {C4, B3, 0, 1, 0, 0, 0, 0, 0},
    {C4, B4, 0, 1, 0, 0, 0, 0, 0},
  };

  int not_expected_move_len = 1;
  move_t not_expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {C4, B5, 0, 1, 0, 0, 0, 0, 0},
  };

  generate_moves(&ml, &board, WHITE);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
  for(int i = 0; i < not_expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(false,
                          is_move_in_list(&ml, &not_expected_moves[i]));
  }
}

void test_generate_king_moves_black(void) {
  parse_fen(&board, "8/1k6/8/1Pp5/2K5/8/8/8 b - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 8;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {B7, A8, 0, 1, 0, 0, 0, 0, 0},
    {B7, B8, 0, 1, 0, 0, 0, 0, 0},
    {B7, C8, 0, 1, 0, 0, 0, 0, 0},
    {B7, A7, 0, 1, 0, 0, 0, 0, 0},
    {B7, C7, 0, 1, 0, 0, 0, 0, 0},
    {B7, A6, 0, 1, 0, 0, 0, 0, 0},
    {B7, B6, 0, 1, 0, 0, 0, 0, 0},
    {B7, C6, 0, 1, 0, 0, 0, 0, 0},
  };

  generate_moves(&ml, &board, BLACK);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_generate_king_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  generate_moves(&ml, &board, WHITE);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, E1));

  empty_move_list(&ml);
  generate_moves(&ml, &board, BLACK);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, E8));
}

void test_generate_rook_moves_white(void) {
  parse_fen(&board, "8/6P1/3k2r1/3P4/3KR3/8/4p3/8 w - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 9;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {E4, E8, 0, 1, 0, 0, 0, 0, 0},
    {E4, E7, 0, 1, 0, 0, 0, 0, 0},
    {E4, E6, 0, 1, 0, 0, 0, 0, 0},
    {E4, E5, 0, 1, 0, 0, 0, 0, 0},
    {E4, E3, 0, 1, 0, 0, 0, 0, 0},
    {E4, E2, 0, 0, 0, 1, 0, 0, 0},
    {E4, F4, 0, 1, 0, 0, 0, 0, 0},
    {E4, G4, 0, 1, 0, 0, 0, 0, 0},
    {E4, H4, 0, 1, 0, 0, 0, 0, 0},
  };

  generate_moves(&ml, &board, WHITE);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_generate_rook_moves_black(void) {
  parse_fen(&board, "8/6P1/3k2r1/3P4/3KR3/8/4p3/8 b - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 9;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {G6, G7, 0, 0, 0, 1, 0, 0, 0},
    {G6, G5, 0, 1, 0, 0, 0, 0, 0},
    {G6, G4, 0, 1, 0, 0, 0, 0, 0},
    {G6, G3, 0, 1, 0, 0, 0, 0, 0},
    {G6, G2, 0, 1, 0, 0, 0, 0, 0},
    {G6, G1, 0, 1, 0, 0, 0, 0, 0},
    {G6, H6, 0, 1, 0, 0, 0, 0, 0},
    {G6, F6, 0, 1, 0, 0, 0, 0, 0},
    {G6, E6, 0, 1, 0, 0, 0, 0, 0},
  };

  generate_moves(&ml, &board, BLACK);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_generate_rook_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  generate_moves(&ml, &board, WHITE);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, A1));

  empty_move_list(&ml);
  generate_moves(&ml, &board, BLACK);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, H8));
}

void test_generate_bishop_moves_white(void) {
  parse_fen(&board, "8/8/3pp3/3b1k2/3K1B2/4PP2/8/8 w - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 6;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {F4, E5, 0, 1, 0, 0, 0, 0, 0},
    {F4, D6, 0, 0, 0, 1, 0, 0, 0},
    {F4, G5, 0, 1, 0, 0, 0, 0, 0},
    {F4, H6, 0, 1, 0, 0, 0, 0, 0},
    {F4, G3, 0, 1, 0, 0, 0, 0, 0},
    {F4, H2, 0, 1, 0, 0, 0, 0, 0},
  };

  generate_moves(&ml, &board, WHITE);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_generate_bishop_moves_black(void) {
  parse_fen(&board, "8/8/3pp3/3b1k2/3K1B2/4PP2/8/8 b - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 8;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {D5, E4, 0, 1, 0, 0, 0, 0, 0},
    {D5, F3, 0, 0, 0, 1, 0, 0, 0},
    {D5, C4, 0, 1, 0, 0, 0, 0, 0},
    {D5, B3, 0, 1, 0, 0, 0, 0, 0},
    {D5, A2, 0, 1, 0, 0, 0, 0, 0},
    {D5, C6, 0, 1, 0, 0, 0, 0, 0},
    {D5, B7, 0, 1, 0, 0, 0, 0, 0},
    {D5, A8, 0, 1, 0, 0, 0, 0, 0},
  };

  generate_moves(&ml, &board, BLACK);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_generate_bishop_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  generate_moves(&ml, &board, WHITE);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, C1));

  empty_move_list(&ml);
  generate_moves(&ml, &board, BLACK);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, F8));
}

void test_generate_queen_moves_white(void) {
  parse_fen(&board, "8/8/8/6QK/6N1/8/3qkn2/8 w - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 17;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {G5, H6, 0, 1, 0, 0, 0, 0, 0},
    {G5, H4, 0, 1, 0, 0, 0, 0, 0},
    {G5, G6, 0, 1, 0, 0, 0, 0, 0},
    {G5, G7, 0, 1, 0, 0, 0, 0, 0},
    {G5, G8, 0, 1, 0, 0, 0, 0, 0},
    {G5, F6, 0, 1, 0, 0, 0, 0, 0},
    {G5, E7, 0, 1, 0, 0, 0, 0, 0},
    {G5, D8, 0, 1, 0, 0, 0, 0, 0},
    {G5, F5, 0, 1, 0, 0, 0, 0, 0},
    {G5, E5, 0, 1, 0, 0, 0, 0, 0},
    {G5, D5, 0, 1, 0, 0, 0, 0, 0},
    {G5, C5, 0, 1, 0, 0, 0, 0, 0},
    {G5, B5, 0, 1, 0, 0, 0, 0, 0},
    {G5, A5, 0, 1, 0, 0, 0, 0, 0},
    {G5, F4, 0, 1, 0, 0, 0, 0, 0},
    {G5, E3, 0, 1, 0, 0, 0, 0, 0},
    {G5, D2, 0, 0, 0, 1, 0, 0, 0},
  };

  generate_moves(&ml, &board, WHITE);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_generate_queen_moves_black(void) {
  parse_fen(&board, "8/8/8/6QK/6N1/8/3qkn2/8 b - - 0 1");
  set_occupancy(&board);

  int expected_move_len = 18;
  move_t expected_moves[] = {
    //s,  t, p, q, d, c, e, k, q
    {D2, D1, 0, 1, 0, 0, 0, 0, 0},
    {D2, E1, 0, 1, 0, 0, 0, 0, 0},
    {D2, C1, 0, 1, 0, 0, 0, 0, 0},
    {D2, C2, 0, 1, 0, 0, 0, 0, 0},
    {D2, B2, 0, 1, 0, 0, 0, 0, 0},
    {D2, A2, 0, 1, 0, 0, 0, 0, 0},
    {D2, C3, 0, 1, 0, 0, 0, 0, 0},
    {D2, B4, 0, 1, 0, 0, 0, 0, 0},
    {D2, A5, 0, 1, 0, 0, 0, 0, 0},
    {D2, D3, 0, 1, 0, 0, 0, 0, 0},
    {D2, D4, 0, 1, 0, 0, 0, 0, 0},
    {D2, D5, 0, 1, 0, 0, 0, 0, 0},
    {D2, D6, 0, 1, 0, 0, 0, 0, 0},
    {D2, D7, 0, 1, 0, 0, 0, 0, 0},
    {D2, D8, 0, 1, 0, 0, 0, 0, 0},
    {D2, E3, 0, 1, 0, 0, 0, 0, 0},
    {D2, F4, 0, 1, 0, 0, 0, 0, 0},
    {D2, G5, 0, 0, 0, 1, 0, 0, 0},
  };

  generate_moves(&ml, &board, BLACK);

  for(int i = 0; i < expected_move_len; i++) {
    TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_moves[i]));
  }
}

void test_generate_queen_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  generate_moves(&ml, &board, WHITE);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, D1));

  empty_move_list(&ml);
  generate_moves(&ml, &board, BLACK);
  TEST_ASSERT_EQUAL_INT(0, count_moves_from_square(&ml, D8));
}

void test_get_pawn_psuedo_moves_single(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  square_t square = E2;
  //                          s,  t, p, q, d, c, e, k, q
  move_t expected_move_w = { E2, E3, 0, 1, 0, 0, 0, 0, 0 };
  get_pawn_psuedo_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move_w));

  square = E7;
  //                          s,  t, p, q, d, c, e, k, q
  move_t expected_move_b = { E7, E6, 0, 1, 0, 0, 0, 0, 0 };
  get_pawn_psuedo_moves(&ml, &board, square, BLACK);
  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move_b));
}

void test_get_pawn_psuedo_moves_double(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);

  square_t square = E2;
  //                          s,  t, p, q, d, c, e, k, q
  move_t expected_move_w = { E2, E4, 0, 1, 0, 0, 0, 0, 0 };
  get_pawn_psuedo_moves(&ml, &board, square, WHITE);

  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move_w));

  square = E7;
  //                          s,  t, p, q, d, c, e, k, q
  move_t expected_move_b = { E7, E5, 0, 1, 0, 0, 0, 0, 0 };
  get_pawn_psuedo_moves(&ml, &board, square, BLACK);
  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move_b));
}

void test_get_castle_psuedo_moves_no_moves(void) {
  parse_fen(&board,
            "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  set_occupancy(&board);
  int expected_move_len = 0;

  get_castle_psuedo_moves(&ml, &board, WHITE);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);

  get_castle_psuedo_moves(&ml, &board, BLACK);
  TEST_ASSERT_EQUAL_INT(expected_move_len, ml.count);
}

void test_get_castle_psuedo_moves_kingside_moves(void) {
  parse_fen(&board,
            "rnbqk2r/pppp1ppp/5n2/2b1p3/2B1P3/5N2/PPPP1PPP/RNBQK2R w KQkq - 0 1");
  set_occupancy(&board);

  //                             s,       t, p, q, d, c, e, k, q
  move_t expected_move = { NULL_SQ, NULL_SQ, 0, 0, 0, 0, 0, 1, 0 };

  get_castle_psuedo_moves(&ml, &board, WHITE);
  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move));

  empty_move_list(&ml);
  get_castle_psuedo_moves(&ml, &board, BLACK);
  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move));
}

void test_get_castle_psuedo_moves_queenside_moves(void) {
  parse_fen(&board,
            "r3kbnr/pp1npppp/2p1q3/3p1b2/3P1B2/2P1Q3/PP1NPPPP/R3KBNR w KQkq - 0 1");
  set_occupancy(&board);

  //                             s,       t, p, q, d, c, e, k, q
  move_t expected_move = { NULL_SQ, NULL_SQ, 0, 0, 0, 0, 0, 0, 1 };

  get_castle_psuedo_moves(&ml, &board, WHITE);
  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move));

  empty_move_list(&ml);
  get_castle_psuedo_moves(&ml, &board, BLACK);
  TEST_ASSERT_EQUAL_INT(true, is_move_in_list(&ml, &expected_move));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_generate_knight_moves_white);
  RUN_TEST(test_generate_knight_moves_black);
  RUN_TEST(test_generate_king_moves_white);
  RUN_TEST(test_generate_king_moves_black);
  RUN_TEST(test_generate_king_no_moves);
  RUN_TEST(test_generate_rook_moves_white);
  RUN_TEST(test_generate_rook_moves_black);
  RUN_TEST(test_generate_rook_no_moves);
  RUN_TEST(test_generate_bishop_moves_white);
  RUN_TEST(test_generate_bishop_moves_black);
  RUN_TEST(test_generate_bishop_no_moves);
  RUN_TEST(test_generate_queen_moves_white);
  RUN_TEST(test_generate_queen_moves_black);
  RUN_TEST(test_generate_queen_no_moves);
  RUN_TEST(test_get_pawn_psuedo_moves_single);
  RUN_TEST(test_get_pawn_psuedo_moves_double);
  RUN_TEST(test_get_castle_psuedo_moves_no_moves);
  RUN_TEST(test_get_castle_psuedo_moves_kingside_moves);
  RUN_TEST(test_get_castle_psuedo_moves_queenside_moves);
  return UNITY_END();
}
