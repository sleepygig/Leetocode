class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
  int n=prices.size();
       int obs=-prices[0];
       int oss=0;
       for(int i=0;i<n;i++)
       {
          int nbs=0;
          int nss=0;
          nbs=max(obs,oss-prices[i]);
          nss=max(oss,obs+prices[i]-fee);   //pepcoding ki vdo nbs is new buy state 
                                        //jo hai max of obs aur phle ka deal off and new opening 
          // deb(i);
          // deb(nbs);
          // deb(nss);
          obs=nbs;
          oss=nss;
       }
     return oss;
    }

};