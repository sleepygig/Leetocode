class Solution {
public:
struct customComparator {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        // Sort by the first element in descending order
        if (a.first > b.first) {
            return true;
        } else if (a.first < b.first) {
            return false;
        } else {
            // Sort by the second element in ascending order
            return a.second < b.second;
        }
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
          mp[words[i]]++;
        }
        vector<pair<int,string>>pq;
        for(auto c:mp)
        {
          pq.push_back({c.second,c.first});
        } 
        sort(pq.begin(),pq.end(),customComparator());
        reverse(pq.begin(),pq.end());
        vector<string>ans;
        while(k--)
        {
          ans.push_back(pq[pq.size()-1].second);
          // deb(pq[pq.size()-1].second);
          pq.pop_back();
        }
        return ans;

    }
};