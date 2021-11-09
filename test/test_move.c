#include <string.h>
#include "../src/move.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_validate_move(void) {
  move_t move = { 0 };
  move.origin = E2;
  move.target = E4;
  move.promotion = P;
  move.quiet_move = false;
  move.double_pawn = true;
  move.capture = false;
  move.ep_capture = false;
  move.kingside_castle = false;
  move.queenside_castle = false;

  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));
}

void test_validate_move_promotion(void) {
  move_t move = { 0 };
  move.origin = E7;
  move.target = E8;

  move.promotion = P;
  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));

  move.promotion = B;
  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));

  move.promotion = N;
  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));

  move.promotion = R;
  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));

  move.promotion = Q;
  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));

  move.promotion = K;
  TEST_ASSERT_EQUAL_INT(FAIL, validate_move(&move, SILENT));

  move.promotion = NULL_P;
  TEST_ASSERT_EQUAL_INT(FAIL, validate_move(&move, SILENT));

  move.promotion = NULL_P + 1;
  TEST_ASSERT_EQUAL_INT(FAIL, validate_move(&move, SILENT));

  move.promotion = P - 1;
  TEST_ASSERT_EQUAL_INT(FAIL, validate_move(&move, SILENT));
}

void test_empty_move_is_invalid(void) {
  move_t move = { 0 };

  TEST_ASSERT_EQUAL_INT(FAIL, validate_move(&move, SILENT));
}

void test_empty_move(void) {
  move_t move = { 0 };

  TEST_ASSERT_EQUAL_INT(A1, move.origin);
  TEST_ASSERT_EQUAL_INT(A1, move.target);
  TEST_ASSERT_EQUAL_INT(P, move.promotion);
  TEST_ASSERT_EQUAL_INT(false, move.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, move.double_pawn);
  TEST_ASSERT_EQUAL_INT(false, move.capture);
  TEST_ASSERT_EQUAL_INT(false, move.ep_capture);
  TEST_ASSERT_EQUAL_INT(false, move.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, move.queenside_castle);
}

void test_encode_decode_squares(void) {
  move_t move = { 0 };
  move_t decoded = { 0 };
  U16 encoded;

  move.origin = A8;
  move.target = H1;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(A8, decoded.origin);
  TEST_ASSERT_EQUAL_INT(H1, decoded.target);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  move.origin = H8;
  move.target = A1;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(H8, decoded.origin);
  TEST_ASSERT_EQUAL_INT(A1, decoded.target);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  move.origin = D4;
  move.target = F3;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(D4, decoded.origin);
  TEST_ASSERT_EQUAL_INT(F3, decoded.target);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  move.origin = C2;
  move.target = E7;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(C2, decoded.origin);
  TEST_ASSERT_EQUAL_INT(E7, decoded.target);
}

void test_encode_decode_flags(void) {
  move_t move = { 0 };
  move_t decoded = { 0 };
  U16 encoded;

  move.quiet_move = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(true, decoded.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, decoded.double_pawn);
  TEST_ASSERT_EQUAL_INT(false, decoded.capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.ep_capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, decoded.queenside_castle);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.double_pawn = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(false, decoded.quiet_move);
  TEST_ASSERT_EQUAL_INT(true, decoded.double_pawn);
  TEST_ASSERT_EQUAL_INT(false, decoded.capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.ep_capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, decoded.queenside_castle);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.capture = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(false, decoded.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, decoded.double_pawn);
  TEST_ASSERT_EQUAL_INT(true, decoded.capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.ep_capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, decoded.queenside_castle);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.ep_capture = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(false, decoded.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, decoded.double_pawn);
  TEST_ASSERT_EQUAL_INT(true, decoded.capture);
  TEST_ASSERT_EQUAL_INT(true, decoded.ep_capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, decoded.queenside_castle);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.kingside_castle = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(false, decoded.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, decoded.double_pawn);
  TEST_ASSERT_EQUAL_INT(false, decoded.capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.ep_capture);
  TEST_ASSERT_EQUAL_INT(true, decoded.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, decoded.queenside_castle);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.queenside_castle = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(false, decoded.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, decoded.double_pawn);
  TEST_ASSERT_EQUAL_INT(false, decoded.capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.ep_capture);
  TEST_ASSERT_EQUAL_INT(false, decoded.kingside_castle);
  TEST_ASSERT_EQUAL_INT(true, decoded.queenside_castle);
}

void test_encode_decode_promotions(void) {
  move_t move = { 0 };
  move_t decoded = { 0 };
  U16 encoded;

  move.promotion = Q;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(Q, decoded.promotion);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.promotion = R;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(R, decoded.promotion);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.promotion = N;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(N, decoded.promotion);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.promotion = B;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(B, decoded.promotion);
}

void test_encode_decode_moves(void) {
  move_t move = { 0 };
  move_t decoded = { 0 };
  U16 encoded;

  move.origin = A7;
  move.target = C8;
  move.capture = true;
  move.promotion = Q;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(A7, decoded.origin);
  TEST_ASSERT_EQUAL_INT(C8, decoded.target);
  TEST_ASSERT_EQUAL_INT(true, decoded.capture);
  TEST_ASSERT_EQUAL_INT(Q, decoded.promotion);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.origin = E1;
  move.target = C1;
  move.queenside_castle = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(E1, decoded.origin);
  TEST_ASSERT_EQUAL_INT(C1, decoded.target);
  TEST_ASSERT_EQUAL_INT(true, decoded.queenside_castle);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.origin = F7;
  move.target = F5;
  move.double_pawn = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(F7, decoded.origin);
  TEST_ASSERT_EQUAL_INT(F5, decoded.target);
  TEST_ASSERT_EQUAL_INT(true, decoded.double_pawn);

  memset(&move, 0, sizeof(move_t));
  memset(&decoded, 0, sizeof(move_t));
  encoded = 0;
  move.origin = E5;
  move.target = D6;
  move.ep_capture = true;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(E5, decoded.origin);
  TEST_ASSERT_EQUAL_INT(D6, decoded.target);
  TEST_ASSERT_EQUAL_INT(true, decoded.ep_capture);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_validate_move);
  RUN_TEST(test_validate_move_promotion);
  RUN_TEST(test_empty_move_is_invalid);
  RUN_TEST(test_empty_move);
  RUN_TEST(test_encode_decode_squares);
  RUN_TEST(test_encode_decode_flags);
  RUN_TEST(test_encode_decode_promotions);
  RUN_TEST(test_encode_decode_moves);
  return UNITY_END();
}
