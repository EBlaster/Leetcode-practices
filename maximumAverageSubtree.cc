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
  pair<int, int> travelTree(TreeNode *root) {
    pair<int, int> tmpLeft;
    pair<int, int> tmpRight;
    double tmpAvg;
    double tmpDownAvg;
    double tmpLeftAvg;
    double tmpRightAvg;
    if (root->left == nullptr && root->right == nullptr) {
      return make_pair(root->val, 1);
    } else {
      if (root->left != nullptr && root->right != nullptr) {
        tmpLeft = travelTree(root->left);
        tmpRight = travelTree(root->right);
        tmpLeftAvg = tmpLeft.first / (double)tmpLeft.second;
        tmpRightAvg = tmpRight.first / (double)tmpRight.second;
        tmpDownAvg = max(tmpLeftAvg, tmpRightAvg);
        tmpAvg = (tmpLeft.first + tmpRight.first + root->val)
                 / ((double)tmpLeft.second + tmpRight.second + 1);
        if (tmpAvg > tmpDownAvg) {
          return make_pair(tmpLeft.first + tmpRight.first + root->val,
                           tmpLeft.second + tmpRight.second + 1);
        } else {
          return tmpLeftAvg > tmpRightAvg ? tmpLeft : tmpRight;
        }
      } else if (root->left != nullptr) {
        tmpLeft = travelTree(root->left);
        tmpDownAvg = tmpLeft.first / (double)tmpLeft.second;
        tmpAvg = (tmpLeft.first + root->val) / ((double)tmpLeft.second + 1);
        if (tmpAvg > tmpDownAvg) {
          return make_pair(tmpLeft.first + root->val, tmpLeft.second + 1);
        } else {
          return tmpLeft;
        }
      } else {
        tmpRight = travelTree(root->right);
        tmpDownAvg = tmpRight.first / (double)tmpRight.second;
        tmpAvg = (tmpRight.first + root->val) / ((double)tmpRight.second + 1);
        if (tmpAvg > tmpDownAvg) {
          return make_pair(tmpRight.first + root->val, tmpRight.second + 1);
        } else {
          return tmpRight;
        }
      }
    }
  }

  double maximumAverageSubtree(TreeNode *root) {
    return travelTree(root).first / (double)travelTree(root).second;
  }
};
