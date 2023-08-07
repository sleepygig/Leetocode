class Solution {
public:
set<vector<int>>ans;
void fs(vector<int>&nums,int n,int i,vector<int>&tp)
    {
        if(i==n)
        {
            // reverse(tp.begin(),tp.end());
            ans.insert(tp);
            return ;
        }
        tp.push_back(nums[i]);
        fs(nums,n,i+1,tp);  //taken
        tp.pop_back();
        fs(nums,n,i+1,tp);   //not takern 
       
    }
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    
     sort(nums.begin(), nums.end());;
    vector<int> tp;
    fs(nums, n, 0, tp);
    vector<vector<int>> a;
    a.insert(a.end(), ans.begin(), ans.end());  // Corrected line

    return a;
}

};