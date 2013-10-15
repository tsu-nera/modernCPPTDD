#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(SoundexEncoding) {
  Soundex soundex;
};

TEST(SoundexEncoding, AppendsZerosToWordForOneLetterWord) {
  CHECK_EQUAL("A000", soundex.encode("A"));
  CHECK_EQUAL("B000", soundex.encode("B"));
}

TEST(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
  CHECK_EQUAL("A100", soundex.encode("Ab"));
}
