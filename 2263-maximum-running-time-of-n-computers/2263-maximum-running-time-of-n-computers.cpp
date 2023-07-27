class Solution {
public:
    long long  krpaiga(vector<int>&batt,long long  lc,long long  mid)
    {
        long long   s=0;
        long long  nb=batt.size();
        for(int i=0;(i<nb and lc);i++)
        {
           if(batt[i]>=mid) {lc--;} 
           else {
            s+=batt[i];
           }    
        }
      
        if(lc) return ((s/lc)>=mid);
        else
        {
            return true;
        }
        return 0;
    }
 long long maxRunTime(int n, vector<int>& batteries) {
    #define lli long long
    lli nb=batteries.size();
    lli lo=0;
    lli hi=1e15;
    lli mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)>>1;
        if(krpaiga(batteries,n,mid))
        {
            lo=mid;
        }
        else 
        {
            hi=mid;
        }   
    }
     if(krpaiga(batteries,n,hi))
        {
            return hi;
        }
        else 
        {
            return lo;
        }
    }
    

};