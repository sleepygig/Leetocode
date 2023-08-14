class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.push(nums[i]);
        }
        k--;
        while(k--)
        {
            s.pop();
        }
        return s.top();
    }
};