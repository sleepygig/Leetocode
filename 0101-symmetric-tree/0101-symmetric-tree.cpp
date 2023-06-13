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
      bool fs(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL and t2==NULL) return true;
        else if(t1==NULL or t2==NULL) return false;
        return (fs(t1->left,t2->right)) and fs(t2->left,t1->right) and t1->val==t2->val;
    }
    bool isSymmetric(TreeNode* root) {
        return fs(root->left,root->right);
    }
};