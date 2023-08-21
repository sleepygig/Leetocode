class Solution {
public:
#define ll long long 
     ll fs(ll i,vector<vector<int>>& rides,vector<ll>&start,vector<ll>&dp)
    {
        
        if(i>=rides.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        ll x=lower_bound(start.begin(),start.end(),rides[i][1])-start.begin();
        ll pc=rides[i][2]+rides[i][1]-rides[i][0]+fs(x,rides,start,dp);
        ll np=fs(i+1,rides,start,dp);
        return dp[i]=max(pc,np);
    }
   long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<ll>dp(rides.size(),-1);
        sort(rides.begin(),rides.end());
        vector<ll>st;
        for(int  i=0;i<rides.size();i++){st.push_back(rides[i][0]);}
        return fs(0,rides,st,dp);

    }

};