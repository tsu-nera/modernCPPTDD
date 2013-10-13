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
    return zeroPad(UpperFront(head(word)) + tail(encodedDigits(word)));
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
    auto it = encodings.find(lower((letter)));
    return it == encodings.end() ? NotADigit : it->second;
  }

private:
  std::string head(const std::string& word) const {
    return word.substr(0, 1);
  }

  std::string UpperFront(const std::string& string) const {
    return std::string(1,
		       std::toupper(static_cast<unsigned char>(string.front())));
  }

  std::string tail(const std::string& word) const {
    return word.substr(1);
  }

  const std::string NotADigit{"*"};

  std::string encodedDigits(const std::string& word) const {
    std::string encoding;
    encodeHead(encoding, word);
    encodeTail(encoding, word);
    return encoding;
  }

  void encodeHead(std::string& encoding, const std::string& word) const {
    encoding += encodedDigit(word.front());
  }

  void encodeTail(std::string& encoding, const std::string& word) const {
    for (auto letter: tail(word))
      if (!isComplete(encoding)) 
	encodeLetter(encoding, letter);
  }

  void encodeLetter(std::string& encoding, char letter) const {
    auto digit = encodedDigit(letter);
    if(digit != NotADigit && digit != lastDigit(encoding))
      encoding += digit;
  }

  std::string lastDigit(const std::string& encoding) const {
    if (encoding.empty()) return NotADigit;
    return std::string(1, encoding.back());
  }

  bool isComplete (const std::string& encoding ) const {
    return encoding.length() == MaxCodeLength;
  }

  char lower(char c) const {
    return std::tolower(static_cast<unsigned char>(c));
  }

  std::string zeroPad(const std::string& word) const {
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + std::string(zerosNeeded, '0');
  }
};

#endif /* SOUNDEX_H_ */
