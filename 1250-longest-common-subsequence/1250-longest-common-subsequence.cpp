class Solution {
public:
 int fs(string &text1,int s1, string &text2,int s2,vector<vector<int>>&dp) {
   
    if(s1==0 or s2==0) return 0;
    if(dp[s1][s2]!=-1) return dp[s1][s2];

if(text1[s1-1]==text2[s2-1])
{
    dp[s1][s2]=1+fs(text1,s1-1,text2,s2-1,dp);
}
else 
{
    dp[s1][s2]=max(fs(text1,s1-1,text2,s2,dp),fs(text1,s1,text2,s2-1,dp));
}
   return dp[s1][s2]; 
}


   int longestCommonSubsequence(string &text1, string &text2) {
        int s1=text1.size();
        int s2=text2.size();
        vector<vector<int>>dp(s1+1,vector<int>(s2+1,-1));
         fs(text1,s1,text2,s2,dp);
        return dp[s1][s2];
    }
};