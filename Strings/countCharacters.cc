#include "headers.h"

class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    int sumLen = 0;
    vector<int> charFreq(26, 0);
    for (auto &&c : chars) {
      charFreq[c - 'a']++;
    }
    for (int i = 0; i < words.size(); i++) {
      vector<int> wordCharFreq(26, 0);
      bool good = true;
      for (auto &&c : words[i]) {
        wordCharFreq[c - 'a']++;
      }
      for (int c = 0; c < 26; c++) {
        if (wordCharFreq[c] > charFreq[c]) {
          good = false;
          break;
        }
      }
      if (good) {
        sumLen += words[i].size();
      }
    }
    return sumLen;
  }
};