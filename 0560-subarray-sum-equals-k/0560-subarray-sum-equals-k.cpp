class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        map<int, int> prefixSumCount;
        
        prefixSumCount[0] = 1;  // Initialize with 0 sum frequency to handle subarrays starting at index 0
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};
