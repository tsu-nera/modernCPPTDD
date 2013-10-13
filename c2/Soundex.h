/*
 * Soundex.h
 *
 *  Created on: 2013/10/13
 *      Author: TSUNEMICHI
 */

#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>
#include <unordered_map>

class Soundex
{
public:
  static const size_t MaxCodeLength{4};
  std::string encode(const std::string& word) const {
    
    return zeroPad(head(word) + encodedDigits(tail(word)));
  }

private:
  std::string head(const std::string& word) const {
    return word.substr(0, 1);
  }

  std::string tail(const std::string& word) const {
    return word.substr(1);
  }

  std::string encodedDigits(const std::string& word) const {
    std::string encoding;
    for (auto letter: word) {
      if (isComplete(encoding)) break;
      encoding += encodedDigit(letter);
    }
    return encoding;
  }

  bool isComplete (const std::string& encoding ) const {
    return encoding.length() == MaxCodeLength - 1;
  }

  std::string encodedDigit(char letter) const {
    const std::unordered_map<char, std::string> encodings {
      {'b', "1"}, {'f', "1"},  {'p', "1"},  {'v', "1"}, 
      {'c', "2"}, {'g', "2"},  {'j', "2"},  {'k', "2"},  {'q', "2"},
		  {'s', "2"},  {'x', "2"},  {'z', "2"},
      {'d', "3"}, {'t', "3"},
      {'l', "4"},
      {'m', "5"}, {'n', "5"},
      {'r', "6"},
    };
    auto it = encodings.find(letter);
    return it == encodings.end() ? "" : it->second;
  }

  std::string zeroPad(const std::string& word) const {
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + std::string(zerosNeeded, '0');
  }
};

#endif /* SOUNDEX_H_ */
