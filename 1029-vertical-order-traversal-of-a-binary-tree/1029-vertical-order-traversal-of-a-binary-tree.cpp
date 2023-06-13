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
#define pi pair<int,int>
    void fs(int c,int r,priority_queue<pair<pi,int>,vector<pair<pi,int>>,greater<pair<pi,int>>>&pq,TreeNode* root)
{
         if(!root) return ;
        pq.push({{c,r},root->val});
        if(root->left) fs(c-1,r+1,pq,root->left);
        if(root->right)fs(c+1,r+1,pq,root->right);
        return ;
}
 vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        priority_queue<pair<pi,int>,vector<pair<pi,int>>,greater<pair<pi,int>>>pq; 
        int r=0;
        int c=0;
        fs(c,r,pq,root);
        // deb(pq.size());
        vector<vector<int>>ans;
        int col=pq.top().first.first;
        vector<int>v;
        while(!pq.empty())
       {
        auto tp=pq.top();
        // deb(tp.second);
       
        if(col==tp.first.first)
       {
        v.push_back(tp.second);
       }
       else 
       {
        ans.push_back(v);
        v.clear();
        v.push_back(tp.second);
        col=tp.first.first;
       }
        pq.pop();
       }
       ans.push_back(v);
    //    for(int i=0;i<ans.size();i++)
    //    {
    //         for(auto c:ans[i])cout<<c<<" ";
    //         cout<<endl;
    //    }
           return ans;
 }
};