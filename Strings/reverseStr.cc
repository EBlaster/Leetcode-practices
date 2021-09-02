#include <headers.h>

class Solution {
 public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.length(); i += k * 2) {
      if (i + k > s.length() - 1) {
        reverse(s.begin() + i, s.end());
      } else {
        reverse(s.begin() + i, s.begin() + i + k);
      }
    }
    return s;
  }
};