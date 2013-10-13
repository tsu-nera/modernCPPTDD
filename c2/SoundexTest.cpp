/*
 * SoundexTest.cpp
 *
 *  Created on: 2013/10/13
 *      Author: TSUNEMICHI
 */
#include "gmock/gmock.h"
#include <string>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return "";
  }
};

TEST(SoundexEncoding, RetainSoleLetterOfOnneLetterWord)
{
  Soundex soundex;

  auto encoded = soundex.encode("A");
}

