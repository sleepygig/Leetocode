class Solution {
public:

long long  cstnikal(vector<int>& nums, vector<int>& cost,long long mid )
{
  #define ll long long 
  ll n=nums.size();
  ll sum=0;
  for(int i=0;i<n;i++)
  {
      sum+=(abs((ll)mid-nums[i]))*(cost[i])*1LL;
  }
  return sum;
}
      long long minCost(vector<int>& nums, vector<int>& cost) {
        #define ll long long 
        ll n=nums.size();
        ll  mx=INT64_MIN,mn=INT64_MAX;
        
        for(int i=0;i<n;i++)
        {
            mx=max(nums[i]*1LL,mx);
            mn=min(mn,nums[i]*1LL);
        }
        ll lo=mn;
        ll hi=mx;
        ll mid;
        while(lo<=hi)
        {
          mid=lo+(hi-lo)/2;
          if(cstnikal(nums,cost,mid)<cstnikal(nums,cost,mid+1))
          {
            hi=mid-1;
          }
          else 
          {
            lo=mid+1;
          }
          // deb(lo);
          // deb(hi);
          // deb(mid);
        }
        ll ans=cstnikal(nums,cost,lo);
        // deb(ans);
        return ans;
        
    }
};