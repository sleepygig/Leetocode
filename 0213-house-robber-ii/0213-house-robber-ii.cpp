   auto fastio=[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return nullptr;}();
class Solution {
public:
      int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        if(n==1) return nums[0];
        dp[1]=nums[0];
         dp[2]=max(nums[1],nums[0]);
        for(int i=3;i<=n-1;i++)
        {
            int a=nums[i-1]+dp[i-2];
            int b=nums[i-2]+dp[i-3];
            dp[i]=max(a,b);
        }
        int a1=dp[n-1];
         memset(dp,0,sizeof(dp));
          dp[1]=0;
         dp[2]=max(nums[1],0);
        for(int i=3;i<=n;i++)
        {
            int a=nums[i-1]+dp[i-2];
            int b=nums[i-2]+dp[i-3];
            dp[i]=max(a,b);
        }
        int a2=dp[n];
    return max(a1,a2);
    }
};