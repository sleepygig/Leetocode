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
     void rv(TreeNode* root,int row,map<int,int>&mp)
    {
        if(root==NULL) return ;
        if(mp.find(row)==mp.end()) mp[row]=root->val;
        if(root->right) rv(root->right,row+1,mp);
        if(root->left)rv(root->left,row+1,mp);
    }
   vector<int> rightSideView(TreeNode* root) {
    if(root==NULL) return {};
    
    int row=0;
    map<int,int>mp;
    rv(root,row,mp);
    vector<int>ans;
    for(auto c:mp)
    {ans.push_back(c.second);}  
    return ans;  
    }
 
};