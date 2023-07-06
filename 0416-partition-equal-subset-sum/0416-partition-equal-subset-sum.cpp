class Solution {
public:
  bool fs(vector<vector<int>>&dp,vector<int>& arr,int n,int sum)
  {
    if(sum==0) return true;
    if(n==0) return false;
    
    
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(sum>=arr[n-1])
    {
      dp[n][sum]=fs(dp,arr,n-1,sum-arr[n-1]) || fs(dp,arr,n-1,sum);
    }
    else 
    {
      dp[n][sum]= fs(dp,arr,n-1,sum);
    }
    return dp[n][sum];
  }
    bool canPartition(vector<int>& nums) {
          int sum=0;
          int n=nums.size();
      for(int i=0;i<n;i++){sum+=nums[i];}
    if(sum&1) return 0;
    sum=sum/2;
       vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
      return fs(dp,nums,n,sum);
       
    }
};