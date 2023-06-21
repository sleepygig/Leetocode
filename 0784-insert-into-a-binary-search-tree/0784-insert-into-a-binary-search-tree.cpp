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
TreeNode* fs(TreeNode* &root,int val)
{
    if(!root){
        root=new TreeNode(val);
        return root;
    }
    TreeNode* a;
   if(root->val>val)
   {
      a=fs(root->left,val);
   }
   else
   {
     a=fs(root->right,val);
   }  
   return a;
}
      TreeNode* insertIntoBST(TreeNode* root, int val) {
        fs (root,val);
        return root;
        
    }
};