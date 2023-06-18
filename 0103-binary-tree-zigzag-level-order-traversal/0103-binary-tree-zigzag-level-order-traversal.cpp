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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {} ;
    	queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
         bool flg=true;
        while(q.size())
        {
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                auto  tp=q.front();
                q.pop();
                if(tp->left) q.push(tp->left);
                 if(tp->right)q.push(tp->right);
                v.push_back(tp->val);
            }
       if(flg==false) {reverse(v.begin(),v.end()); ans.push_back(v) ; flg=!flg;}
            else if(flg==true){ans.push_back(v);flg=!flg;}
        }
        return ans;
    }
};