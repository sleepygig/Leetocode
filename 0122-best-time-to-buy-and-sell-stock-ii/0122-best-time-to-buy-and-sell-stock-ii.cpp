class Solution {
public:
int fs(int i, vector<int>& prices, vector<vector<int>>& dp, bool buy) {
   if(i==prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
   if(buy==true)
   {
    int sell=prices[i]+fs(i+1,prices,dp,false);
    int notsell= fs(i+1,prices,dp,buy);
    dp[i][buy]=max(sell,notsell);
   }
   else
   {
    int by=-prices[i]+fs(i+1,prices,dp,true);
    int notby= fs(i+1,prices,dp,buy);
    dp[i][buy]=max(by,notby);
   }
   return dp[i][buy];
}
int maxProfit(vector<int>& prices) {
   vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
    int b = fs(0, prices, dp, false);              // Not buying on the first day
    return  b;
}
};