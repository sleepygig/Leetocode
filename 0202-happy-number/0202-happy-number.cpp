class Solution {
public:
int ans(int n)
    {
        int ans=0;
        while(n>0)
        {
            int x =n%10;
            ans+=pow(x,2);
            n=n/10;
        }
        return ans;
    }
       bool isHappy(int n) {
        unordered_map<int,int>mp;

        while(n!=1 and  mp.find(n)==mp.end())
        {
            // deb(n);
            mp[n]=1;
            n=ans(n);
        }
        if(n==1)
        {
            return true;
        }
        return false;
    }
};