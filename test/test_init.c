#include "../src/init.h"
#include "../src/board.h"
#include "../src/bitboard.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_init_rays(void) {
  TEST_ASSERT_EQUAL_INT(0, rays[0][0]);

  init_rays();

  TEST_ASSERT_EQUAL_INT(1157442765139738624ULL, rays[NORTH][E4]);
  TEST_ASSERT_EQUAL_INT(9241421688455823360ULL, rays[NO_EAST][D4]);
  TEST_ASSERT_EQUAL_INT(16252928ULL, rays[EAST][C3]);
  TEST_ASSERT_EQUAL_INT(567382630219904ULL, rays[SO_EAST][A8]);
  TEST_ASSERT_EQUAL_INT(8224ULL, rays[SOUTH][F3]);
  TEST_ASSERT_EQUAL_INT(16416ULL, rays[SO_WEST][H3]);
  TEST_ASSERT_EQUAL_INT(7936ULL, rays[WEST][F2]);
  TEST_ASSERT_EQUAL_INT(16777216ULL, rays[NO_WEST][B3]);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_init_rays);
  return UNITY_END();
}
