#include "headers.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  struct State {
    // count of nodes in the subtree
    int nodeCount;

    // sum of values in the subtree
    int valueSum;

    // max average found in the subtree
    double maxAverage;
  };

 public:
  State travelTree(TreeNode *root) {
    if (!root) {
      return {0, 0, 0};
    } else {
      State left = travelTree(root->left);
      State right = travelTree(root->right);

      int nodeCount = left.nodeCount + right.nodeCount + 1;
      int sum = left.valueSum + right.valueSum + root->val;
      double maxAverage = max((1.0 * (sum)) / nodeCount,
                              max(right.maxAverage, left.maxAverage));
      return {nodeCount, sum, maxAverage};
    }
  }

  double maximumAverageSubtree(TreeNode *root) {
    return travelTree(root).maxAverage;
  }
};
