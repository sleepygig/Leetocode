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
   TreeNode* lgega(TreeNode* &root,int &val)
    {   TreeNode* a;
          if (!root) {
        root = new TreeNode(val);  // Create a new node
        return root;
    }
      
        a=(root->val>val) ? lgega(root->left,val): lgega(root->right,val);
       
        return a; 
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        lgega(root,val);
        return root;
    }
};