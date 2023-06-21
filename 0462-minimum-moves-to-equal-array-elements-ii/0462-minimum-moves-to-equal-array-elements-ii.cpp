class Solution {
public:
  int   cstnikal(vector<int>& nums,int  mid )
{
  #define ll long long 
  int n=nums.size();
  ll sum=0;
  for(int i=0;i<n;i++)
  {
      sum+=(abs(mid-nums[i]));
  }
  return sum;
}
     int minMoves2(vector<int>& nums) {
        int n=nums.size();
      int mx=INT32_MIN;
        int mn=INT32_MAX;
        for(int i=0;i<n;i++)
        {
          mx=max(mx,nums[i]);
          mn=min(mn,nums[i]);
        }
        int lo=mn;
        int hi=mx;
        int mid;
        while(hi-lo>1)
        {
          mid=(lo+hi)>>1;
          if(cstnikal(nums,mid)<cstnikal(nums,mid+1))
          {hi=mid;}
          else{
            lo=mid;
          }
        }
        int ans=(cstnikal(nums,lo)<cstnikal(nums,hi))? cstnikal(nums,lo): cstnikal(nums,hi);
        return ans;

    }
};