class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums)
   {
    int n=nums.size();
    
      int ans =INT32_MAX;
     int psum[n+1];
     psum[0]=nums[0];
     for(int i=1;i<n;i++)
     {
        psum[i]=psum[i-1]+nums[i];
     }
     psum[n]=0;
       int i=0;
      int j=0;
     while(j<n )
     {
      if(psum[j]-psum[i]+nums[i]<target)
      {
        j++;
      }
      else 
      {
        
        while(psum[j]-psum[i]+nums[i]>=target)
        {
          ans =min(ans,j-i+1);
          i++;
        }
      }
     }
  int a=(ans==INT32_MAX)? 0: ans;
  // deb(a);
  return a;
   }
};