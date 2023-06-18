class Solution {
public:
   vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,int>hm;
        for(auto &c:nums){for( auto  &x: c)hm[x]++;}
        vector<int>ans;
        for(auto &c:hm)
        {if(c.second==n) ans.push_back(c.first);}
        return ans;
      }
};