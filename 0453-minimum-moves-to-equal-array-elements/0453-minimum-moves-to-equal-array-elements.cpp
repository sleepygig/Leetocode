class Solution {
public:
    int minMoves(vector<int>& nums) {
      int minValue = *std::min_element(nums.begin(), nums.end());

    // Step 2: Calculate the differences and sum them up
    int moves = 0;
    for (int num : nums) {
        moves += num - minValue;
    }

    // Step 3: Return the total number of moves
    return moves;
    
    }
};