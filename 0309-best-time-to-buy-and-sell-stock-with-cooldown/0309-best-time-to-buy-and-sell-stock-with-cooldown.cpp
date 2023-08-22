class Solution {
public:
int fs(int i,vector<int>& prices,vector<vector<int>>&dp,int buy)
{
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy)
    {
        int sl= +prices[i]+fs(i+2,prices,dp,0);
        int ns=fs(i+1,prices,dp,buy);
        dp[i][buy]=max(sl,ns);
    }
    else 
    {
         int b= -prices[i]+fs(i+1,prices,dp,1);
        int nb=fs(i+1,prices,dp,0);
        dp[i][buy]=max(b,nb);
    }
    return dp[i][buy];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return fs(0,prices,dp,0);
    }

};