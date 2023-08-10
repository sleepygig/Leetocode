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
   TreeNode* fs(vector<int> pos,int s,int e)
    {
        if(e<s) return NULL;
        TreeNode* root= new TreeNode(pos[s]);


        if(s==e) return root;

        int a=e+1;
        for(int i=s+1;i<=e;i++)
        {
            if(pos[i]>root->val)
            {
                a=i;
                
                break;
            }
        }
        root->left=fs(pos,s+1,a-1);
        root->right=fs(pos,a,e);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size=preorder.size();
         return fs( preorder,0,size-1);
    }

};