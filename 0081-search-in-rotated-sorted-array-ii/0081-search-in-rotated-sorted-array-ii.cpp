class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n=nums.size();
       int lo=0;
       int hi=n-1;
       int mid=(hi+lo)>>1;
       while(hi>=lo)
       {
           mid=(hi+lo)>>1;
           if(nums[mid]==target)
           {
               return true;
           }
           if(nums[lo]==nums[mid] and nums[mid]==nums[hi])
           {
               lo++;
               hi--;
               continue;
           }
           else if (nums[mid]<=nums[hi])  //right half is sorted
            {
                if(nums[mid]<=target and target<=nums[hi])
                {
                    lo=mid+1;
                }
                else

                {
                    hi=mid-1;
                }
            }
            else       //left half is sorted 
            {
                 if(nums[lo]<=target and target<=nums[mid])
                {
                    hi=mid-1;
                }
                else

                {
                    lo=mid+1;
                }
            }               
           
       }
       return false; 
    }
};