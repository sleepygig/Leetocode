class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
      if(nums.size()==0) return {-1,-1};
        int s=0;
        int e=nums.size()-1;
        int mid;
        while(e-s>1)
        {
            mid=(s+e)>>1;
            
             if(nums[mid]>=target)
            {
                e=mid;
            }
            else if(nums[mid]<target)
            {
                s=mid;
            }
        }
         vector<int>v;
        if(nums[s]==target)
        {
            v.push_back(s);
        }
        else if(nums[e]==target) 
        {
            v.push_back(e);
        }
        else 
        {
            v.push_back(-1);
        }
         s=0;
         e=nums.size()-1;
         mid;
            while(e-s>1)
        {
            mid=(s+e)>>1;
            
             if(nums[mid]>target)
            {
                
                e=mid;
            }
            else if(nums[mid]<=target)
            {
                s=mid;
            }
        }
        if(nums[e]==target)
        {
            v.push_back(e);
        }
        else if(nums[s]==target) 
        {
            v.push_back(s);
        }
        else 
        {
            v.push_back(-1);
        }
    // for(auto c:v)
    // {cout<<c<<" ";}
        return v;
    }
};