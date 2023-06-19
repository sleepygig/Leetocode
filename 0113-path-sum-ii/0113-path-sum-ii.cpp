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
   bool isleaf(TreeNode* root) {
    return (root->left == NULL && root->right == NULL);
} 
    void fs(TreeNode* root, int targetSum ,vector<vector<int>>&ans,vector<int>&v,int cur)
    {
         if(!root) return ;
        cur+=root->val;
        v.push_back(root->val);
        if( isleaf(root) and  targetSum==cur){ans.push_back(v);}
        
        if(root->left)fs(root->left,targetSum,ans,v,cur);
        if(root->right)fs(root->right,targetSum,ans,v,cur);
        v.pop_back();
    }

  	   vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          vector<vector<int>>ans;
          vector<int>q;
          int cur=0;
          fs(root,targetSum,ans,q,cur);
          return ans;

    }
};