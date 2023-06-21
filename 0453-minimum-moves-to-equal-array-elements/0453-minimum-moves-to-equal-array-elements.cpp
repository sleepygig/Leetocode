class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=INT32_MAX   ;
        int sum=0;
      for(int i=0;i<n;i++)
      {
          sum+=nums[i];
          mn=min(nums[i],mn);
      }
      int ans=sum - mn * n ;
      return ans;
    }
};