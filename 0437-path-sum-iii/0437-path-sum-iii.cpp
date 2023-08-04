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
void fs(TreeNode* root, ll s, unordered_map<ll, ll>& mp, ll k, ll& cnt) {
    if (root == nullptr) return;

    // Calculate the current sum from the root to the current node
    s += root->val;

    // Check if (s - k) exists in the map, which means there is a valid path
    // from some ancestor node to the current node that sums up to k.
    if (mp.find(s - k) != mp.end()) {
        cnt += mp[s - k];
    }

    // Increment the frequency of the current sum in the map
    mp[s]++;

    // Traverse left and right subtrees
    fs(root->left, s, mp, k, cnt);
    fs(root->right, s, mp, k, cnt);

    // Decrement the frequency as we backtrack
    mp[s]--;
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