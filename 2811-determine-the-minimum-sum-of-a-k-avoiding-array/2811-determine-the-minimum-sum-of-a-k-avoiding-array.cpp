class Solution {
public:
bool fin(vector<int>v,int cnt,int k)
{
    for(int i=0;i<v.size();i++)
    {
        if(cnt+v[i]==k) return false;
    }
    return true;
}
    int minimumSum(int n, int k) {
        if(n==1  and k==1) return 1;
        if( n==1 and k!=1) return n;
        vector<int>ans;
        ans.push_back(1);
        int cnt=2;
        while(ans.size()!=n)
        {
            if((cnt+1)!=k and fin(ans,cnt,k) )
            {
                ans.push_back(cnt);
                cnt++;
            }
            else 
            {
                cnt++;
            }
        }
        int a=accumulate(ans.begin(),ans.end(),0);
        // for(auto c:ans)
        // {cout<<c<<" ";}
         return a;
    }
};