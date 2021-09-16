#include "headers.h"

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    bool left = false;
    bool right = false;
    for (int i = 0; i < nums.size(); i++) {
      if (right == true) {
        left = true;
        right = false;
      } else {
        left = false;
        right = false;
      }

      if (i == 0) {
        left = true;
        if (nums.size() == 1) {
          return 0;
        }
        if (nums[i] > nums[i + 1]) {
          right = true;
        }
      } else if (i == nums.size() - 1) {
        right = true;
        if (nums[i] > nums[i - 1]) {
          left = true;
        }
      } else {
        if (nums[i] > nums[i - 1]) {
          left = true;
        }
        if (nums[i] > nums[i + 1]) {
          right = true;
        }
      }

      if (left && right) {
        return i;
      }
    }
    return 0;
  }
};