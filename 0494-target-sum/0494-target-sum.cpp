class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        #define lli long long
        int sum=0;
        int d=abs(target); 
        int n=nums.size();
      for(lli i=0;i<n;i++)
    {
        sum+=nums[i];    
    }
      if((d+sum)%2 != 0) return 0;
      sum=(d+sum)/2;
    vector<vector<lli>>dp(n+1,vector<lli> (sum+1,0));
    for(lli i=0;i<=n;i++)
    {
       for(lli j=0;j<=sum;j++)
       {
           
            if(i==0)
            {
                dp[i][j]=0;
            }
       }
    }
    dp[0][0]=1;
        for(lli i=1;i<=n;i++)
        {
       for(lli j=0;j<=sum;j++)
       {
            if(nums[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-nums[i-1]]+dp[i-1][j]);
            }
            else 
            {
                dp[i][j]=dp[i-1][j];
            }
       }
    }
    // print2d(dp,n,sum);

   return dp[n][sum];       
    }
};