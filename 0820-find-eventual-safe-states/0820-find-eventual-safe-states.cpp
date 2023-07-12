class Solution {
public:
     bool cyle(vector<int>&vis,vector<int>&path,int src,vector<vector<int>>& graph)
    {
        vis[src]=1;
        path[src]=1;
        for(auto c:graph[src])
        {
            if(!vis[c])    //nya child jo kis visited nahi hai 
            {
                if(cyle(vis,path,c,graph)) return true;   // agr cycle mille toh backtracking mei bhi true return kro 
            }
            else if(path[c])
            {
                return true ;
            }
        }
        path[src]=0; // unsetting the path from the orgin if comming out of it .
        return false;
    }
 vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
        vector<int>vis(n+1,0);
        vector<int>path(n+1,0);

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
                if(!cyle(vis,path,i,graph))
                {
                    ans.push_back(i);
                }
        }
        return ans;
    }
};