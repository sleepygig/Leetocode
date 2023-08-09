/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *fs(vector<int> &inorder, vector<int> &postorder, int si, int ei, int sp, int ep,
             unordered_map<int, int> &hm) {
    if (si > ei || sp > ep) return NULL;
    TreeNode *root = new TreeNode(postorder[ep]);
    int ri = hm[postorder[ep]];
    int nl = ri - si;
    root->left = fs(inorder, postorder, si, ri - 1, sp, sp + nl - 1, hm);
    root->right = fs(inorder, postorder, ri + 1, ei, sp + nl, ep - 1, hm);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> hm;
    for (int i = 0; i < inorder.size(); i++) {
        hm[inorder[i]] = i;
    }
    int n = inorder.size();
    return fs(inorder, postorder, 0, n - 1, 0, n - 1, hm);
}

};