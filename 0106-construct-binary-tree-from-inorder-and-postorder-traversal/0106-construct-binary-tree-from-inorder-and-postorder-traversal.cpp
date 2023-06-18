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
TreeNode* ans(vector<int>& postorder, vector<int>& inorder,int startpos,int endpos,int startin
   ,int endin,map<int,int>&indxmp)
   {
    if(startin>endin or startpos>endpos) return NULL;
    int  vals=postorder[endpos];   //root ki value 
    TreeNode * root=new TreeNode(vals);
    int rootindx=indxmp[vals];
    int lstsze=rootindx-startin;
    int rstsze=endin-rootindx;
    root->right=ans(postorder,inorder,startpos+lstsze,endpos-1,rootindx+1,endin,indxmp);
    root->left=ans(postorder,inorder,startpos,startpos+lstsze-1,startin,rootindx-1,indxmp);
    return root; 
   } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>indxmp;
      int n=inorder.size();
      for(int i=0;i<n;i++)
      {
            indxmp[inorder[i]]=i;
      } 
      return ans(postorder,inorder,0,n-1,0,n-1,indxmp);  
    }
};