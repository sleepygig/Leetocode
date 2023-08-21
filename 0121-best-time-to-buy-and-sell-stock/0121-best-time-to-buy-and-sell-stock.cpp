class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=prices.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            pq.push(prices[i]);
            ans=max(ans,prices[i]-pq.top());
        }

        return ans;
    }
};