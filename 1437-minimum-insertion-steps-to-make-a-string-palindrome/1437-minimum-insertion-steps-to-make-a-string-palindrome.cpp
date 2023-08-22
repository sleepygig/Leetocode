class Solution {
public:
    int minInsertions(string s) {
        string text2=s;
        reverse(s.begin(),s.end());
         int s1=s.size();
        int s2=text2.size();
        vector<vector<int>>dp(s1+1,vector<int>(s2+1,0));
         for(int i=1;i<=s1;i++)
         {
             for(int j=1;j<=s2;j++)
             {
                 if(text2[i-1]==s[j-1])
                 {
                     dp[i][j]=dp[i-1][j-1]+1;
                 }
                 else 
                 {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
             }
         }
    
    return s1-dp[s1][s2];
    }
};