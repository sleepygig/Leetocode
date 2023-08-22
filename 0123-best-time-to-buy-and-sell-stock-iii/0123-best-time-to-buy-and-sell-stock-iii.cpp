class Solution {
public:
int fs(int i, vector<int>& prices, vector<vector<vector<int>>>& dp, bool buy,int ch) {
   if(i==prices.size()) return 0;
   if(ch<0) return 0;

   if(dp[i][buy][ch]!=-1) return dp[i][buy][ch];
    if(buy==0 and ch>=0)
    {
        int by=-prices[i]+fs(i+1,prices,dp,true,ch-1);
        int nb=fs(i+1,prices,dp,buy,ch);
        dp[i][buy][ch]=max(by,nb);
    }
    else if(buy==true)
    {
       int sl=+prices[i]+fs(i+1,prices,dp,false,ch);
        int ns=fs(i+1,prices,dp,buy,ch);
        dp[i][buy][ch]=max(sl,ns);  
    }
    return dp[i][buy][ch];
}
int maxProfit(vector<int>& prices) {
   vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));

    int b = fs(0, prices, dp, false,2);              // Not buying on the first day
    return  b;
}

};