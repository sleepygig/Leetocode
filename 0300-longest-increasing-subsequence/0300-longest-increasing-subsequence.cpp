class Solution {
public:
int fs(vector<int>&dp, vector<int>&nums,int n){
    if(n==0) return 1;
    int xx=1;
    if(dp[n]!=-1) return dp[n];
    for(int i=0;i<n;i++)
    {
        if(nums[i]<nums[n]) xx=max(1+fs(dp,nums,i),xx);     
    }
    dp[n]=xx;
    return dp[n];
    }
  int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
        vector<int>dp(n,-1);

         fs(dp,nums,n-1);
         int y=0;
  
         for(int i=0;i<n;i++)
         {
            y=max(fs(dp,nums,i),y);
         }
        //         for(auto c:dp)
        //  {cout<<c<<" ";}
         return y;

    }

};