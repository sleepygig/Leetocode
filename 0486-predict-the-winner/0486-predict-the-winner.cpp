class Solution {
public:
  int sc(vector<int>& nums, int i, int j, int sum, bool& a, vector<vector<int>>& dp) {
    if (i == j) return nums[i];
    if (i > j) return 0;

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int l = nums[i] + min(sc(nums, i + 2, j, sum, a, dp), sc(nums, i + 1, j - 1, sum, a, dp));
    int r = nums[j] + min(sc(nums, i + 1, j - 1, sum, a, dp), sc(nums, i, j - 2, sum, a, dp));

    dp[i][j] = max(l, r);
    return dp[i][j];
}

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    bool a = false;
    if (n == 1) return true;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int x = sc(nums, 0, n - 1, sum, a, dp);
    return x >= sum - x;
}
};