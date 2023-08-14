class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int>s;
       int i=0;
       int j=0;
       int n=nums.size();
       vector<int>ans;
       while(j!=n)
       {
        while(s.size()!=k)
        {
            s.insert(nums[j]);
            j++;
        }
        ans.push_back(*s.rbegin());
        s.erase(s.lower_bound(nums[i]));
        i++;
       }
       return ans;
   }
};