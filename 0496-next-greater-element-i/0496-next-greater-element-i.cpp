class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        for(int i=0;i<n;i++) mp[nums2[i]]=i;
        vector <int>ans;
        stack<int>st;
        for(int i=n-1;i!=-1;i--)
        {
            while(st.size() and st.top()<nums2[i]) st.pop();
            if(st.size()==0) ans.push_back(-1);
            else if(st.top()>nums2[i]) ans.push_back(st.top());
            st.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        vector<int>fin;
        for(int i=0;i<nums1.size();i++)

        {
            fin.push_back(ans[mp[nums1[i]]]);
        }
        return fin;
    }
};