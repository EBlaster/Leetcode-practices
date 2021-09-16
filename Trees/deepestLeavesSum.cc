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
 public:
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    } else {
      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
  }

  int sumLeaves(int currdepth, int depth, TreeNode *root) {
    if (!root) {
      return 0;
    } else if (currdepth != depth) {
      return sumLeaves(currdepth + 1, depth, root->left) +
             sumLeaves(currdepth + 1, depth, root->right);
    } else {
      return root->val;
    }
  }

  int deepestLeavesSum(TreeNode *root) {
    int depth = maxDepth(root);
    int sum = sumLeaves(1, depth, root);
    return sum;
  }
};