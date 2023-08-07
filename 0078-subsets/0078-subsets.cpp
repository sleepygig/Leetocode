class Solution {
public:
    void fs(vector<int>&nums,int n,int i,vector<int>&tp,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            // reverse(tp.begin(),tp.end());
            ans.push_back(tp);
            return ;
        }
        tp.push_back(nums[i]);
        fs(nums,n,i+1,tp,ans);  //taken
        tp.pop_back();
        fs(nums,n,i+1,tp,ans);   //not takern 
       
    }


 vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>tp;
    int n=nums.size();
    vector<vector<int>>ans;
    fs(nums,n,0,tp,ans);
      return ans;
 }
};