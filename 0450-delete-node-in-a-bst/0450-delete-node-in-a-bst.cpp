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
   TreeNode* findMax(TreeNode* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // levelOrderTraversal(root);
        

       if(!root) return NULL;
       if(root->val>key)
       {
        root->left=deleteNode(root->left,key);
       }
       else if(root->val<key)
       {
        root->right=deleteNode(root->right,key);
       } 
        else 
        {    //yh function wo node return krega jo inplace iyegi delted node ki 
            if(root->left!=nullptr and root->right!=nullptr)
            {
                TreeNode* maxNode = findMax(root->left);
                root->val = maxNode->val;
                root->left = deleteNode(root->left, maxNode->val);
            }
            else if (root->left!=nullptr)
            {
              return root->left;
            }
            else if(root->right!=nullptr)
            {
                return root->right;
            }
            else 
            {
                return nullptr;
            }

        }
        // levelOrderTraversal(root);
        return root;
    }
};