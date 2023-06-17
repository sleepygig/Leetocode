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
  void treetoGr(TreeNode* root,map<int ,vector<int>>&adj)
{
  if(!root) return ;
  int par=root->val;
  if(root->left) {
    int l=root->left->val;
    adj[l].push_back(par);
    adj[par].push_back(l);
      treetoGr(root->left,adj);
  }
  
  if(root->right) {
    int r=root->right->val;
    adj[r].push_back(par);
    adj[par].push_back(r);
      treetoGr(root->right,adj);
  }
}
void bfs(map<int ,vector<int>>&adj,map<int,int>&vis,int src,int &ans)
{
    queue<pair<int,int>>q;   //node //lvl
    q.push({src,0});
    while(q.size())
    {
        int tp=q.front().first;
        int lv=q.front().second;
        vis[tp]=1;
        ans=max(ans,lv);
        q.pop();
        for(auto c:adj[tp])
        {if(!vis[c]) q.push({c,lv+1});}
    }
}
      int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>>adj;
        treetoGr(root,adj);
        int ans=INT_FAST32_MIN;
        map<int,int>vis;
        bfs(adj,vis,start,ans);
        // deb(ans);
    return ans;
    }
};