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
        if(isleaf(root)){s.push_back((root->val)); ans.push_back(s);  s.pop_back(); return ;}
        s.push_back(root->val);
        fs(root->left,ans,s);
        fs(root->right,ans,s);
        // s.pop_back();
       
    }
     vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>s;
        vector<vector<int>>ans;
        fs(root,ans,s);
        vector<string>fa;
       for(int i=0;i<ans.size();i++)
       {
         string q;
           for(auto c:ans[i])
           {q=q+to_string(c);
           q=q+"->";}
           q.pop_back();
           q.pop_back(); 
           fa.push_back(q);
       }
       return fa;
        
    }
};