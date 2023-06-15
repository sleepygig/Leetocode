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
   vector<int> rightSideView(TreeNode* root) {
    if(root==NULL) return {};
        map<int,int>mp;
        queue<pair<int ,TreeNode*>>q;
        q.push({0,root});
        while(q.size())
        {
            TreeNode* tpnode=q.front().second;
            int row=q.front().first;
            q.pop();
            if(mp.find(row)==mp.end()) mp[row]=tpnode->val;
            if(tpnode->right) q.push({row+1,tpnode->right});
            if(tpnode->left)q.push({row+1,tpnode->left});
        }
        vector<int>ans;
        for(auto c:mp)
        {ans.push_back(c.second);}
        // for(auto c:ans)
        // {cout<<c<<" ";}
        return ans;
    }
 
};