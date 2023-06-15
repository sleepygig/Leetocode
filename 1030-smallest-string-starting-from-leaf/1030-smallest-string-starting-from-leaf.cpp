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
 void solve(TreeNode* root,string s,vector<string> &v)
    {
        if(root==nullptr)
            return ;
        s+=(char)(root->val+97);
        if(!root->left&&!root->right)
        {
            string temp=s;
            reverse(temp.begin(),temp.end());
            v.push_back(temp);
        }
        solve(root->left,s,v);
        solve(root->right,s,v);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v;
        string s="";
        solve(root,s,v);
        sort(v.begin(),v.end());
        return v[0];
    }  
    
};