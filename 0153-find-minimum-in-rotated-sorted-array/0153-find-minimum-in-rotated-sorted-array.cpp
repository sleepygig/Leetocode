class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int n=nums.size();
        int hi=n-1;
        int mid;
        int ans=INT_MAX;
        while(hi-lo>1)
        {
            mid=(hi+lo)>>1;
            if(nums[lo]<=nums[mid])
            {
                ans=min(ans,nums[lo]);  //left issorted
                lo=mid; 
            }
            else if(nums[mid]<nums[hi]) 
            {
                ans=min(ans,nums[mid]);
                hi=mid;
                
            }
        }
        return min({nums[lo],nums[hi],ans});
        
    }
};