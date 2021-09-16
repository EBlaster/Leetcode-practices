#include "headers.h"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool searchBST(TreeNode* node, int target) {
    if (node == nullptr) {
      return false;
    } else if (node->val == target) {
      return true;
    } else if (node->val < target) {
      return searchBST(node->right, target);
    } else {
      return searchBST(node->left, target);
    }
  }

  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    if (root1 == nullptr) {
      return false;
    } else if (searchBST(root2, target - root1->val)) {
      return true;
    } else {
      return twoSumBSTs(root1->left, root2, target) ||
             twoSumBSTs(root1->right, root2, target);
    }
  }
};