/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (!root) return NULL;
   if (root == p || root == q) return root;

   TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
   TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

   if (leftLCA && rightLCA) return root;  // LCA found, one node in left subtree and the other in the right subtree
   if (leftLCA) return leftLCA;  // LCA found in the left subtree
   if (rightLCA) return rightLCA;  // LCA found in the right subtree

   return NULL;  // L
    }
};