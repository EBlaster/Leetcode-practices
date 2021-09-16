#include "headers.h"

class NumArray {
  int n;
  vector<int> arr;
  vector<vector<int>> sums;

 public:
  NumArray(vector<int>& nums) {
    arr = nums;
    n = nums.size();

    for (int i = 0; i < n; i++) {
      sums.push_back(vector<int>(n, 0));
      sums[i][i] = arr[i];
      for (int j = i + 1; j < n; j++) {
        sums[i][j] = sums[i][j - 1] + arr[j];
      }
    }
  }

  void update(int index, int val) {
    for (int i = 0; i <= index; i++) {
      for (int j = index; j < n; j++)
      {
        sums[i][j] += val - arr[index];
      }
    }

    arr[index] = val;
  }

  int sumRange(int left, int right) { return sums[left][right]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */