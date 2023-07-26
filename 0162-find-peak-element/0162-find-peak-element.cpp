class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        nums.insert (nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        int lo=1;
        int n=nums.size();
        int hi=n-2;
        while(hi>=lo)
        {
            int mid=(lo+hi)>>1;
            if(nums[mid-1]<nums[mid] and nums[mid]>nums[mid+1])
            {
                return mid-1;
            }
            else if(nums[mid]<nums[mid+1])
            {
                lo=mid+1;
            }
            else if(nums[mid-1]>nums[mid])
            {
                hi=mid-1;
            }
        }
    return 0;
    }
};