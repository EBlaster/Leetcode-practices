#include <headers.h>

// Definition for a binary tree node.
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
  int binaryToDecimal(vector<int>& num) {
    int currPos = 1;
    int sum = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
      sum += num[i] * currPos;
      currPos *= 2;
    }
    return sum;
  }

  void calcTreeNums(TreeNode *root, vector<int> &branchNum,
                    vector<vector<int>> &treeNums) {
    if (root == nullptr) {
      treeNums.push_back(branchNum);
    } else {
      branchNum.push_back(root->val);
      if (root->left != nullptr) {
        vector<int> leftBranchNum = branchNum;
        calcTreeNums(root->left, leftBranchNum, treeNums);
      }
      if (root->right != nullptr) {
        vector<int> rightBranchNum = branchNum;
        calcTreeNums(root->right, rightBranchNum, treeNums);
      }
      if (root->left == nullptr && root->right == nullptr) {
        treeNums.push_back(branchNum);
      }
    }
  }

  int sumRootToLeaf(TreeNode *root) {
    vector<vector<int>> treeNums;
    vector<int> branchNum;
    int sum = 0;
    calcTreeNums(root, branchNum, treeNums);
    for (auto &&i : treeNums) {
      sum += binaryToDecimal(i);
    }
    return sum;
  }
};