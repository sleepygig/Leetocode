class Solution {
public:
int fs(int n ,map<int,int>&dp)
{
    if(n==1 or n==0) return 1;
    if(dp[n]) return dp[n];
    return dp[n]=fs(n-1,dp)+fs(n-2,dp);
}
    int climbStairs(int n) {
        map<int,int>dp;
        return fs(n,dp);
    }
};