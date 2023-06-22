class Solution {
public:
#define lli long long 
lli kitneb(vector<int>& a,int k ,int mid )
{
  lli n=a.size();
  lli i=0;
  lli j=0;
  lli b=0;
  lli sb=0;
  while(j<n)
  { sb=0;
    if(a[j]<=mid)
    {
      j++;
    }
    else
    {
   
      sb=j-i;
      b+=(sb/k);
      j++;
      i=j;
    }
  }
      sb=j-i;
      b+=(sb/k);
    return b;
}
 
      int minDays(vector<int>& bloomDay, int m, int k) {
        #define lli long long 
        lli n=bloomDay.size();
    if ((long long)m * k > n) return -1;
        int l=0;
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans =0;
        while(h>=l)
        {
          int mid=(l+h)>>1;
          if(kitneb(bloomDay,k,mid)>=m*1LL)  //mid no of day usmei kitne B bna skta  
          {
            ans=mid;
            h=mid-1;  
          }
          else 
          {
            l=mid+1; 
          } 
          // deb(l);
          // deb(ans);
        }
        
        return ans;}

};