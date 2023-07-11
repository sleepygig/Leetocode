// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        #define lli long long 
        lli s=1;
        lli e=n;
        lli mid;
        lli ans=0;
        while(e>s)
        {
          mid=(e+s)/2;
          if(isBadVersion(mid))
          {
              e=mid;
          } 
          else 
          {
              s=mid+1;
          }
        }
        return e;
    }
};