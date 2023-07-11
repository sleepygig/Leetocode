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
void TtG(TreeNode* root, map<int ,vector<int>>&adj)
    {
        if(!root) return ;
        if(root->left)
        {
            int par=root->val;
            int ch=root->left->val;
            adj[par].push_back(ch);
            adj[ch].push_back(par);
            TtG(root->left,adj);
        }
         if(root->right)
        {
            int par=root->val;
            int ch=root->right->val;
            adj[par].push_back(ch);
            adj[ch].push_back(par);
            TtG(root->right,adj);
        }
        return ;
    }
   void bfs(map<int ,vector<int>>&adj,vector<int>&vis,int k,int src,vector<int>&ans)
{
    queue<pair<int,int>>q;   //node //lvl
    q.push({src,0});
    while(q.size())
    {
        int tp=q.front().first;
        int lv=q.front().second;
        vis[tp]=1;
        if(lv==k) ans.push_back(tp);
        q.pop();
        for(auto c:adj[tp])
        {if(!vis[c]) q.push({c,lv+1});}
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        map<int ,vector<int>>adj;
        TtG(root,adj);
        int src=target->val; 
        vector<int>vis(501,0);
         vector<int>ans;
    bfs(adj,vis,k,src,ans);
    return ans;     
    }
};