#include "../src/move.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_validate_move(void) {
  move_t move;
  move.origin = E2;
  move.target = E4;
  move.promotion = NULL_P;
  move.quiet_move = true;
  move.double_pawn = true;
  move.capture = false;
  move.ep_capture = false;
  move.kingside_castle = false;
  move.queenside_castle = false;

  TEST_ASSERT_EQUAL_INT(SUCCESS, validate_move(&move, SILENT));
}

void test_empty_move_is_invalid(void) {
  move_t move = { 0 };

  TEST_ASSERT_EQUAL_INT(FAIL, validate_move(&move, SILENT));
}

void test_empty_move(void) {
  move_t move = { 0 };

  TEST_ASSERT_EQUAL_INT(A8, move.origin);
  TEST_ASSERT_EQUAL_INT(A8, move.target);
  TEST_ASSERT_EQUAL_INT(P, move.promotion);
  TEST_ASSERT_EQUAL_INT(false, move.quiet_move);
  TEST_ASSERT_EQUAL_INT(false, move.double_pawn);
  TEST_ASSERT_EQUAL_INT(false, move.capture);
  TEST_ASSERT_EQUAL_INT(false, move.kingside_castle);
  TEST_ASSERT_EQUAL_INT(false, move.queenside_castle);
}

void test_encode_decode(void) {
  move_t move = { 0 };
  move_t decoded = { 0 };
  U16 encoded;

  move.origin = A8;
  move.target = H1;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(A8, decoded.origin);
  TEST_ASSERT_EQUAL_INT(H1, decoded.target);

  move.origin = H8;
  move.target = A1;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(H8, decoded.origin);
  TEST_ASSERT_EQUAL_INT(A1, decoded.target);

  move.origin = D4;
  move.target = F3;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(D4, decoded.origin);
  TEST_ASSERT_EQUAL_INT(F3, decoded.target);

  move.origin = C2;
  move.target = E7;
  encoded = encode_move(&move);
  decode_move(&decoded, encoded);
  TEST_ASSERT_EQUAL_INT(C2, decoded.origin);
  TEST_ASSERT_EQUAL_INT(E7, decoded.target);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_validate_move);
  RUN_TEST(test_empty_move_is_invalid);
  RUN_TEST(test_empty_move);
  RUN_TEST(test_encode_decode);
  return UNITY_END();
}
