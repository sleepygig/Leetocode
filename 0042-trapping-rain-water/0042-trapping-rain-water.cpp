class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>f(n,0);
        vector<int>s(n,0);
        f[0]=height[0];
        for(int i=1;i<n;i++)
        {
            f[i]=max(f[i-1],height[i]);
        }
        s[n-1]=height[n-1];
           for(int i=n-2;i!=-1;i--)
        {
            s[i]=max(s[i+1],height[i]);
        }
        int ans=0;

           for(int i=0;i<n;i++)
        {
            ans+=min(s[i],f[i])-height[i];
        }
    
        return ans;
    }
};