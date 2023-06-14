class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int n=gas.size();
       vector<int>v(n);
       for(int i=0;i<n;i++)
       {
         v[i]=gas[i]-cost[i];
       } 
       if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
       int t=0;
       int ans =0;
       for(int i=0;i<n;i++)
       {
         t+=v[i];
         if(t<0) 
         {
            t=0;
         ans=i+1;
          
         }

       }
  return ans;
    }
};