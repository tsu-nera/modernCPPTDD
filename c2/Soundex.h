/*
 * Soundex.h
 *
 *  Created on: 2013/10/13
 *      Author: TSUNEMICHI
 */

#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>

class Soundex{
public:
  std::string encode(const std::string& word) const {
    return zeroPad(word);
  }

private:
  std::string zeroPad(const std::string& word) const {
    return word + "000";
  }
};


#endif /* SOUNDEX_H_ */
