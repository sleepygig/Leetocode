class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        long long int a[n+1];
        a[0]=0;
        for(int i=0;i<n;i++){
            a[i+1]=a[i]+nums[i];
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i-k<0||i+k>=n) ans.push_back(-1);
            else{
                ans.push_back((a[i+k+1]-a[i-k])/(2*k+1));
            }
        }

        return ans;
    }
};