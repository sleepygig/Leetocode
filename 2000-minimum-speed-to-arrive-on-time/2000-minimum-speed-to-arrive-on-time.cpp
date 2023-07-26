class Solution {
public:
  double tt(vector<int>& dis, int speed)
    {
         double tt=0;
        int n=dis.size();
        for(int i=0;i<n-1;i++)
        {
            double ct=ceil((double)dis[i]/speed);
			// deb(ct);
            tt+=ct;
        }
        tt=tt+((double)dis[n-1]/speed);
    return tt;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo=1;   //bs on speed wh
        int hi=1e7;
        int mid;
        while(hi-lo>1)
        {
            mid=(lo+hi)>>1;
            if(tt(dist,mid)<=hour)
            {
                hi=mid;
            }
			else
			{
				lo=mid+1;
			}
			// deb(lo);
			// deb(hi);
        }
		if(tt(dist,lo)<=hour)
		{
			return lo;
		}
		else if(tt(dist,hi)<=hour)
		{
			return hi;
		}
		else
		{
			return -1;
		}
    }
};