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
 int mxhe(TreeNode*root,int &x)
    {
        if(!root) return 0;
        int l=mxhe(root->left,x);
        int r=mxhe(root->right,x);
        return max(l,r)+1;
    }
  int maxDepth(TreeNode* root) {
    int a=0;
       return mxhe(root,a);

    }
};