class Solution {
public:
  bool topo(vector<int>adj[],vector<int>&vis, int src ,vector<int>&path)
    {
        vis[src]=1;
        path[src]=1;
        for(auto c:adj[src])
        {
            if(!vis[c])
            {
                if(topo(adj,vis,c,path)) return true;;    //kahi child pe cycle milli toh just return ki cycle exit krti hai 
            }
            else if(path[c])
            {
                return true;      //Cycle detected
            }
        }
         path[src]=0;
         return false;
    }
         bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int n=numCourses;
            vector<int>adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
              int source = prerequisites[i][0];
            int destination = prerequisites[i][1];
            adj[destination].push_back(source);
        }
                                                                                                                                                                                             
        vector<int>vis(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++)
        {
                if(!vis[i])
                {
                    if(topo(adj,vis,i,path))
                    {
                        return false;
                    }
                }
        }
        return true;
        
    }
};