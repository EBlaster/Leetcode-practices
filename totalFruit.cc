#include "headers.h"

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int lastType = -1;
    int lastLength = 0;
    int maxLength = 0;
    int currLength = 0;
    vector<int> currTypes = {-1, -1};

    if (fruits.size() == 1) {
      return 1;
    } else if (fruits.size() == 2) {
      return 2;
    } else {
      if (fruits[0] == fruits[1]) {
        lastType = fruits[0];
        lastLength = 2;
        maxLength = 2;
        currTypes[1] = fruits[1];
        currLength = 2;
      } else {
        lastType = fruits[1];
        lastLength = 1;
        maxLength = 2;
        currTypes[0] = fruits[0];
        currTypes[1] = fruits[1];
        currLength = 2;
      }
    }

    for (int i = 2; i < fruits.size(); i++) {
      if (fruits[i] != currTypes[0] && fruits[i] != currTypes[1]) {
        currTypes[0] = currTypes[1];
        currTypes[1] = fruits[i];
        currLength = lastLength + 1;
        lastType = fruits[i];
        lastLength = 1;
      } else if (fruits[i] == currTypes[0] || fruits[i] == currTypes[1]) {
        if (lastType != fruits[i]) {
          lastType = fruits[i];
          lastLength = 1;
          currLength++;
          currTypes[0] = currTypes[1];
          currTypes[1] = fruits[i];
        } else {
          lastLength++;
          currLength++;
        }
      }
      maxLength = maxLength > currLength ? maxLength : currLength;
    }

    return maxLength;
  }
};