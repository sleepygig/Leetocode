class Solution {
public:
    bool fs(int i,int j,set<string>&st,string s,vector<vector<int>>&dp)
    {
        if(j==s.size() and i==s.size()) return true;
         if(j==s.size() and i!=s.size()) return false;
         if(dp[i][j]!=-1) return dp[i][j];

           string tp=s.substr(i,j-i+1);
           bool a=false;
           if(st.find(tp)!=st.end())
           {
            bool x=fs(j+1,j+1,st,s,dp);
            bool y=fs(i,j+1,st,s,dp);
            dp[i][j]= x or y;
           }
           else 
           {
             dp[i][j]=fs(i,j+1,st,s,dp);
           }
           return dp[i][j];
    }
 
      bool wordBreak(string s, vector<string>& wordDict) {
       set<string>st;
       for(auto c:wordDict)st.insert(c);
       int n=s.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return fs(0,0,st,s,dp);

       
    }
};
