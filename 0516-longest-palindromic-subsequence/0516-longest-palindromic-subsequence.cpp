auto fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
    
public:
  
     int longestPalindromeSubseq(string s) {
        int x=s.size();
        
        string q=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(x+1,vector<int>(x+1,0));
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=x;j++)
            {
                if(s[i-1]==q[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else 
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][x];

    }
};