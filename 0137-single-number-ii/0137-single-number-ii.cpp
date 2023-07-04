class Solution {
public:
        int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int a=0;
  
        vector<int>bit(32,0);
        for(auto c:nums)
        {
            for(int i=0;i<32;i++)
            {
                if(c&1)
                {
                    bit[i]++;
                }
                c=c>>1;
            }
        }
        long long ans=0;
        for(int i=0;i<32;i++)
        {
            if(bit[i]%3)
            {
                ans+=pow(2,i)*1LL;
            }
        }
       return ans;

    }
};