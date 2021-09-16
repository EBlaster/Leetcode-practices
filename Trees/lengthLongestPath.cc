#include "headers.h"

// Definition for a tree node.
template <typename T>
struct TreeNode {
  T val;
  vector<TreeNode> *children;
  TreeNode() : val(0), children() {}
  TreeNode(T x) : val(x), children() {}
  TreeNode(T x, vector<TreeNode> *children) : val(x), children(children) {}
};
class Solution {
 public:
  int lengthLongestPath(string input) {

  }
};