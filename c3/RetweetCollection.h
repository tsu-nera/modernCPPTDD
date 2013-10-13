#ifndef RetweetCollection_h
#define RetweetCollection_h

#include "Tweet.h"

class RetweetCollection {
 public:
  RetweetCollection()
    : empty_(true) {
  }

  bool isEmpty() const {
    return empty_;

  }
  
  void add(const Tweet& tweet) {
    empty_ = false;
  }

  void remove(const Tweet& tweet) {
    empty_ = true;
  }

  unsigned int size() const {
    return 0;
  }

 private:
  bool empty_;
};

#endif
