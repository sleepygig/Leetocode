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
   TreeNode* searchBST(TreeNode* root, int val) {
       TreeNode* a;
        if(root==NULL) return NULL;
        // deb(root->val);
        if(root->val==val) return root;
        else if(root->val>=val){ a= searchBST(root->left,val);}
        else { a= searchBST(root->right,val); }
        return a;
    }
};