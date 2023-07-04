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
   bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q==NULL and p==NULL) return true ;    //ek null hai 
        if(q==NULL and p!=NULL) return false ;   //dono null 
        if(p==NULL and q!=NULL) return false ;
        // deb(p->data);
        // deb(q->data);
        bool l=isSameTree(p->left,q->left);
        bool r=isSameTree(p->right,q->right);
        return l and r and q->val==p->val;
    }
};