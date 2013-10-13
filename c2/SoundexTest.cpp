/*
 * SoundexTest.cpp
 *
 *  Created on: 2013/10/13
 *      Author: TSUNEMICHI
 */
#include "gmock/gmock.h"

class Soundex {
};

TEST(SoundexEncoding, RetainSoleLetterOfOnneLetterWord)
{
  Soundex soundex;

  auto encoded = soundex.encode("A");
}


