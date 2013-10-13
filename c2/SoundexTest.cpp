/*
 * SoundexTest.cpp
 *
 *  Created on: 2013/10/13
 *      Author: TSUNEMICHI
 */
#include "gmock/gmock.h"
#include <string>

using namespace testing;

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(word);
  }

private:
  std::string zeroPad(const std::string& word) const {
    return word + "000";
  }
};

TEST(SoundexEncoding, RetainSoleLetterOfOnneLetterWord)
{
  Soundex soundex;

  auto encoded = soundex.encode("A");
  ASSERT_THAT(encoded, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
  Soundex soundex;

  auto encoded = soundex.encode("I");
  ASSERT_THAT(encoded, Eq("I000"));
}
