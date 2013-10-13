#include "gmock/gmock.h"

using namespace ::testing;

struct Sumcase {
  int a, b, expected;
  Sumcase(int anA, int aB, int anExpected)
    : a(anA), b(aB), expected(anExpected) {}
};

class AnAdder: public TestWithParam<Sumcase> {
  
};

class Adder {
public:
  static int sum(int a, int b) {
    return a + b;
  }
};

TEST(AnAdder, GenerateASumFromTwoNumbers) {
  ASSERT_THAT(Adder::sum(1, 1), Eq(2));
}

TEST_P(AnAdder, GenerateLotsOfSumsFromTwoNumbers) {
  Sumcase input = GetParam();
  ASSERT_THAT(Adder::sum(input.a, input.b), Eq(input.expected));
}

Sumcase sums[] = {
  Sumcase(1,1,2),
  Sumcase(1,2,3),
  Sumcase(2,2,4)
};

INSTANTIATE_TEST_CASE_P(BulkTest, AnAdder, ValuesIn(sums));
