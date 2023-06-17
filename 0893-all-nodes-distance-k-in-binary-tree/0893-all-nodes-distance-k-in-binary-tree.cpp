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
 void treetoGr(TreeNode* root,TreeNode * target,map<int ,vector<int>>&adj,int &y)
{
  if(!root) return ;
  int par=root->val;
  if(root->left) {
    int l=root->left->val;
    adj[l].push_back(par);
    adj[par].push_back(l);
      treetoGr(root->left,target,adj,y);
  }
  
  if(root->right) {
    int r=root->right->val;
    adj[r].push_back(par);
    adj[par].push_back(r);
      treetoGr(root->right,target,adj,y);
  }
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
   vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    int y=0;
    map<int,vector<int>>adj;
    treetoGr(root,target,adj,y);
    for(auto c:adj)
    {cout<<c.first<<" ";
    for(auto x:c.second)
    {cout<<x<<" ";}
    cout<<endl;}
    vector<int>vis(501,0);
    vector<int>ans;
    bfs(adj,vis,k,target->val,ans);
    return ans;
    for(auto c:ans){cout<<c<<" ";}

    }
};