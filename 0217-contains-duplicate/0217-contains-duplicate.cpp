class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto c:nums)
        {mp[c]++;}
        for(auto c:mp)
        {if(c.second>=2)return true;}
        return false;
    }
};