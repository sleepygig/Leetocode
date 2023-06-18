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
    TreeNode *ans(vector<int>& preorder, vector<int>& inorder,int startpre,int endpre,int startin
   ,int endin,unordered_map<int,int>&indxmp)
   {
    if(startin>endin or startpre>endpre) return NULL;
    int  vals=preorder[startpre];
    TreeNode* root = new TreeNode(vals);
    int rootindx=indxmp[vals];
    int lstsze=rootindx-startin;
    root->left=ans(preorder,inorder,startpre+1,startpre+lstsze,startin,rootindx-1,indxmp);
    root->right=ans(preorder,inorder,startpre+lstsze+1,endpre,rootindx+1,endin,indxmp);
    return root;


    
   } 
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int,int>indxmp;
      int n=inorder.size();
      for(int i=0;i<n;i++)
      {
            indxmp[inorder[i]]=i;
      } 
      return ans(preorder,inorder,0,n-1,0,n-1,indxmp); 

    }
};