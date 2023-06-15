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
void fs(TreeNode* root,vector<vector<int>>&ans,vector<int> s)
    {
        if(!root) return ;
        if(isleaf(root)){s.push_back((root->val)); reverse(s.begin(),s.end());
        ans.push_back(s); return ;}
        s.push_back(root->val);
        fs(root->left,ans,s);
        fs(root->right,ans,s);       
    }
      string smallestFromLeaf(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>s;
        fs(root,ans,s);
        sort(ans.begin(),ans.end());
        vector<int>a =ans[0];
        string st;
        for(int i=0;i<a.size();i++)
        {
            st=st+char(a[i]+'a');   
        }
        // reverse(st.begin(),st.end());
        return st;
      }
};