#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

class Solution {
public:
    int fs(unordered_map<int, char> &mp, string s, int j, vector<int> &dp) {
        if (j == s.size()) return 1;
        if (dp[j] != -1) return dp[j];
        
        int ways = 0;
        for (int i = j; i < s.size(); ++i) {
            string t = s.substr(j, i - j + 1);
            int a;
            stringstream(t) >> a;
            
            if (mp.find(a) != mp.end() && t[0] != '0') {
                ways += fs(mp, s, i + 1, dp);
            } else {
                break;  // Stop considering further substrings if invalid
            }
        }
        
        dp[j] = ways;
        return ways;
    }

    int numDecodings(string s) {
        unordered_map<int, char> mp;
        if (s[0] == '0') return 0;
        for (char i = 'a'; i <= 'z'; i++) {
            mp[i - 96] = i;
        }

        vector<int> dp(s.size() + 1, -1);
        return fs(mp, s, 0, dp);
    }
};
