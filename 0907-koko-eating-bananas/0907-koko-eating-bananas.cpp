class Solution {
public:
long long  timetocomp(vector<int>& piles,int mid )
{
  int n=piles.size();
  long long  tot=0;
  for(int i=0;i<n;i++)
  {
      tot += (piles[i] + mid - 1) / mid; 
  }
  return tot;
}
     int minEatingSpeed(vector<int>& piles, int h) {
      
        int lo=1;
        int hi=1e9;
        int mid;
        while(hi-lo>1)
        {
          mid = lo + (hi - lo) / 2;
          if(timetocomp(piles,mid)<=h)
          {
            hi=mid;
          }
          else
          {
            lo=mid;
          }
     
        }
       int ans=(timetocomp(piles,lo)<=h)? lo :hi;
    
       return ans ;
    }
};