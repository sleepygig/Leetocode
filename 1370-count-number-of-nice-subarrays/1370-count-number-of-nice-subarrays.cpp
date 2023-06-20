class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int n=nums.size();
      for(int i=0;i<n;i++)
      {
         nums[i]=nums[i]%2; 
      }
      int cnt=0;
      for(auto c:nums){cout<<c<<" ";}
     int psum[n];
      map<int,int>mp;
     psum[0]=nums[0];
    mp[0]=1;    //starting point 


    mp[psum[0]]++;
     for(int i=1;i<n;i++)
     {
        psum[i]=psum[i-1]+nums[i];
        mp[psum[i]]++;
     }
     int ans=0;
     for(int c=0;c<n;c++)
     {
      int x=psum[c]+k-nums[c];
      if(mp.find(x)!=mp.end())
      {
        ans+=mp[x];
      }
      // deb(ans);
     }
     return ans;
     

     
     }
};