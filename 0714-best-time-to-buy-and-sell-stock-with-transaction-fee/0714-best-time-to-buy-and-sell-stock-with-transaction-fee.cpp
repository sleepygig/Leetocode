class Solution {
public:
int fs(int i,vector<int>& prices,vector<vector<int>>&dp,int buy,int fee)
{
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy==1)
    {
        int sl=fs(i+1,prices,dp,0,fee)+prices[i]-fee;
        int ns=fs(i+1,prices,dp,buy,fee);
        dp[i][buy]=max(sl,ns);
    }
    else if(buy==0)
    {
         int b=fs(i+1,prices,dp,1,fee)-prices[i];
        int nb=fs(i+1,prices,dp,0,fee);
        dp[i][buy]=max(b,nb);
    }
    return dp[i][buy];
}
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return fs(0,prices,dp,0, fee);
    }
};