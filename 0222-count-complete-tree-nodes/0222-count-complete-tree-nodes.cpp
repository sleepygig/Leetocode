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
   int a(TreeNode * root,int &y)
{
    if(!root) return 0;
    if(root->left)y=y+1;
    if(root->right)y=y+1;
    a(root->left,y);
    a(root->right,y);
    // deb(y);
    return y;
    
}
 int countNodes(TreeNode* root) {
    int y=1;
      return a(root,y);  
    }
};