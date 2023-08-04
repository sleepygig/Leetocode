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
#define ll long long 
  void  fs(TreeNode* root,ll s,unordered_map<ll,ll>&mp,ll k,ll &cnt)
    {

      if(root==NULL) return ;
        if(root->left==NULL and root->right==NULL)
        {
            s+=root->val;
        if (mp.find(s - k) != mp.end()) {
        cnt += mp[s - k];
   
    }



         return ;
        }
        s+=root->val;
        if (mp.find(s - k) != mp.end()) {
        cnt += mp[s - k];
    }
        mp[s]++;
         if(root->left) fs(root->left,s,mp,k,cnt);
          if (root->right) fs(root->right,s,mp,k,cnt);
          mp[s]--;
        //   s-=root->data;
          return ;
      
    }
 int pathSum(TreeNode* root, int targetSum) {
    ll s=0;
    unordered_map<ll,ll>mp;
    mp[0]=1;
    ll cnt=0;
    ll k=targetSum;
    fs(root,s,mp,k,cnt);
    return cnt;

      

      
    }
};