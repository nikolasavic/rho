#include "../src/defs.h"
#include "../unity/unity.h"

void setUp(void) {
}

void tearDown(void) {
}


int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_square_names);
  return UNITY_END();
}
