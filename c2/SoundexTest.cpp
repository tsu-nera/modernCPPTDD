/*
 * SoundexTest.cpp
 *
 *  Created on: 2013/10/13
 *      Author: TSUNEMICHI
 */
#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public testing::Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, RetainSoleLetterOfOnneLetterWord)
{
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
  ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlhabetics)
{
  ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, DISABLED_ReplaceMultipleConsonantsWithDigits)
{
  ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters)
{
  ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoreVowelLikeLetters)
{
  ASSERT_THAT(soundex.encode("Baeiouhycdl"), Eq("B234"));
}

