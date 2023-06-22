class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values of nums[i]
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        int target = -nums[i];
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                left++;
                while (left < right && nums[left] == nums[left - 1])
                    left++;
            } else if (nums[left] + nums[right] > target) {
                right--;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            } else {
                vector<int> triplet = {nums[i], nums[left], nums[right]};
                ans.push_back(triplet);
                
                left++;
                right--;
                
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
        }
    }
    
    return ans;
}

      
};