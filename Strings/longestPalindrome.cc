#include <headers.h>

class Solution {
public:
  string longestPalindrome(string s) {
    int maxLen = 0;
    int maxPos = 0;
    bool typeOdd = true;

    for (int i = 0; i < s.length(); i++) {
      int currLen = 0;

      if (i > 0 && i < s.length() - 1 && s[i - 1] == s[i + 1]) {
        for (int j = 1; i-j >= 0 && i+j < s.length(); j++) {
          if (s[i-j] == s[i+j]) {
            currLen++;
          } else {
            break;
          }
        }
        if (currLen > maxLen) {
          maxLen = currLen;
          maxPos = i;
          typeOdd = true;
        }
      }

      currLen = 0;

      if (i < s.length() - 1 && s[i] == s[i + 1]) {
        for (int j = 1; i-j >= 0 && i+j+1 < s.length(); j++) {
          if (s[i-j] == s[i+j+1]) {
            currLen++;
          } else {
            break;
          }
        }
        if (currLen >= maxLen) {
          maxLen = currLen;
          maxPos = i;
          typeOdd = false;
        }
      }
    }

    if (typeOdd) {
      return s.substr(maxPos - maxLen, maxLen * 2 + 1);
    } else {
      return s.substr(maxPos - maxLen, maxLen * 2 + 2);
    }
  }
};