class Solution {
public:
int fs(unordered_map<int,char>&mp,string s,int i,int j,vector<vector<int>>&dp)
    {
        if (i==s.size() and j==s.size()) return 1;
        if (i!=s.size() and j==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        string t=s.substr(i,j-i+1);
        int a;
        stringstream(t) >> a;
        if(mp.find(a)!=mp.end()  and t[0]!='0')
        {
            return dp[i][j]=fs(mp,s,j+1,j+1,dp)+fs(mp,s,i,j+1,dp);
        }
        else if(t[0]=='0')
        {

            return 0;
        }

        else 
        {

        return dp[i][j]=fs(mp,s,i,j+1,dp);
        }
        return 0;
    }
   int numDecodings(string s) {
    unordered_map<int ,char>mp;
    if(s[0]=='0') return 0;
    for(char i='a';i<='z';i++)
        {
            mp[i-96]=i;
        }
          vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return fs(mp,s,0,0,dp);
      
     
    }
};