class Solution {
public:
int numDecodings(string s) {
    unordered_map<int ,char>mp;

    for(char i='a';i<='z';i++)
        {
            mp[i-96]=i;
        }
           int n=s.size();
          vector<vector<int>>dp(n+1,vector<int>(n+1,0));

       
          dp[n][n]=1;
          for(int j=n-1;j>=0;j--)
          {
              for(int i=0;i<=j;i++)
              {
                  string t=s.substr(i,j-i+1);
                    int a;
                   stringstream(t) >> a;
                   if(mp.find(a)!=mp.end())
                   {
                    dp[i][j]=dp[j+1][j+1] +dp[i][j+1];
                   }
                    else if(t[0]=='0' or a>=27)
                    {
                        continue;
                    }
                   else
                   {
                    dp[i][j]=dp[i][j+1];
                   }  
          }
    }
  
    return dp[0][0];
    
   
   }
};