class Solution {
public:
   int sc(vector<int>& nums, int i, int j) {
    if (i == j) return nums[i];
    if (i > j) return 0;

    int left = nums[i] + min(sc(nums, i + 2, j), sc(nums, i + 1, j - 1));
    int right = nums[j] + min(sc(nums, i + 1, j - 1), sc(nums, i, j - 2));

    return max(left, right);
}

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return true;

    int player1Score = sc(nums, 0, n - 1);
    int totalScore = accumulate(nums.begin(), nums.end(), 0);
    int player2Score = totalScore - player1Score;

    return player1Score >= player2Score;
}

};