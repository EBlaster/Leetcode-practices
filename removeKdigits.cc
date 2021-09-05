#include "headers.h"

class Solution {
public:
  string removeKdigits(string num, int k) {
    bool erased = false;
    int currPos = 0;
    while (k > 0) {
      erased = false;
      for (int i = 0; i < num.length() - 1; i++) {
        if (num[i] > num[i+1] && !erased) {
          num.erase(num.begin() + i);
          k--;
          erased = true;
          break;
        }
      }
      if (!erased) {
        while (k > 0) {
          num.erase(num.end() - 1);
          k--;
        }
      }
    }

    while (num[0] == '0') {
      num.erase(num.begin());
    }

    if (num == "") {
      return "0";
    } else {
      return num;
    }
  }
};