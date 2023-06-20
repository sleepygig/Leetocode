class Solution {
public:
 vector<int> getAverages(vector<int>& nums, int k) {
   #define ll long long 
      int n=nums.size();
        vector<int>ans(n,-1);
        ll psum[n];
        psum[0]=nums[0];
        for(int i=1;i<n;i++) psum[i]=psum[i-1]+nums[i]; 

        for(int i=k;i<n;i++)
        {
          if(i>=k and i+k<n)
          {
            ans[i]=(psum[i+k]-psum[i-k]+nums[i-k])/(2*k+1);
            // ans[i]/=(2*k+1); 
          }
        }
        return ans;
    }
};