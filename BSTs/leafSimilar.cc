#include <headers.h>

//Definition for a binary tree node.
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
  bool isLeaf(TreeNode* node) {
    if (node != nullptr && node->left == nullptr && node->right == nullptr) {
      return true;
    } else {
      return false;
    }
  }

  void leafSeq(TreeNode* root, vector<int>& seq) {
    if (root == nullptr) {
      return;
    } else if (isLeaf(root)) {
      seq.push_back(root->val);
    } else {
      leafSeq(root->left, seq);
      leafSeq(root->right, seq);
    }
  }

  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> seq1;
    vector<int> seq2;
    leafSeq(root1, seq1);
    leafSeq(root2, seq2);
    for (auto &&i : seq1) {
      cout << i << ' ';
    }
    cout << endl;
    for (auto &&i : seq2) {
      cout << i << ' ';
    }
    cout << endl;

    if (seq1 == seq2) {
      return true;
    } else {
      return false;
    }
  }
};