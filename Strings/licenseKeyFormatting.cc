#include "headers.h"

class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    s.erase(remove(s.begin(), s.end(), '-'), s.end());
    for (auto &&i : s) {
      i = toupper(i);
    }

    for (int i = s.size() - k; i >= 1; i -= k) {
      s.insert(i, "-");
    }

    return s;
  }
};