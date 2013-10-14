#include "Portfolio.h"

using namespace std;

Portfolio::Portfolio() : shareCount_{0u} {
}

bool Portfolio::IsEmpty() const { 
  return 0 == shareCount_;
}

void Portfolio::Purchase(const string& symbol, unsigned int shareCount) {
   shareCount_ = shareCount;
}

unsigned int Portfolio::ShareCount(const string& symbol) const {
   return shareCount_;
}
