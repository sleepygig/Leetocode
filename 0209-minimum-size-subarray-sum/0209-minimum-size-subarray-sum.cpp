class Solution {
public:
 int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = INT_MAX;

    while (j < n) {
        sum += nums[j];
        if (sum < target) {
            j++;
        } 
               else 
        {
          while(sum>=target)
          {
            if(sum>= target)ans=min(ans,j-i+1);
            sum-=nums[i];
            i++;
          }
          j++;
        }
    }
    //  ans = min(j - i + 1, ans);

    int a = (ans == INT_MAX) ? 0 : ans;
    return a;
}

};