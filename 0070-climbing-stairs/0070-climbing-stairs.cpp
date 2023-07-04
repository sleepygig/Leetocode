class Solution {
public:
    int totst(map<int,int>&dp,int n)
{
    if(n==0 or n==1) return 1;
    if(dp[n]) return dp[n];
    int l=totst(dp,n-1);
    int r=totst(dp,n-2);
    return dp[n]=l+r;

}
 int climbStairs(int n) {
       
    map<int,int>dp;
    return totst(dp,n);

    }
};