#include <headers.h>

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int red, white, blue = 0;
    for (auto &&i : nums) {
      if (i == 0) red++;
      if (i == 1) white++;
      if (i == 2) blue++;
    }
    for (int i = 0; i < red; i++) {nums[i] = 0;}
    for (int i = red; i < white + red; i++) {nums[i] = 1;}
    for (int i = red + blue; i < white + red + blue; i++) {nums[i] = 2;}

    return;
  }
};