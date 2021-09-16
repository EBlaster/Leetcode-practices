#include "headers.h"

class Solution {
 public:
  vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    for (auto&& i : nums1) {
      result.push_back(find(nums2.begin(), nums2.end(), i) - nums2.begin());
    }

    return result;
  }
};