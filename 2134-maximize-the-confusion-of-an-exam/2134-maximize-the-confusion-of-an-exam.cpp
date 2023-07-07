class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int n = answerKey.size();
    int maxConsecutive = 0;
    int maxCount = 0;
    int start = 0;
    int countT = 0;
    int countF = 0;

    for (int end = 0; end < n; end++) {
        if (answerKey[end] == 'T') {
            countT++;
        } else {
            countF++;
        }

        // Check if the number of operations used up
        // exceeds the allowed limit
        while (min(countT, countF) > k) {
            if (answerKey[start] == 'T') {
                countT--;
            } else {
                countF--;
            }
            start++;
        }

        maxConsecutive = max(maxConsecutive, end - start + 1);
    }

    return maxConsecutive;
}

};