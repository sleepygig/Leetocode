class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int l=0;
       int n=arr.size();
       int h=n-1;
       int mid=0;
       while(h>=l)
       {
           mid=(l+h)/2;
            // deb(mid);
           if(arr[mid-1]<arr[mid] and arr[mid ]>arr[mid+1])
           {
            // deb(mid);
               return mid ;
           }
           else if(arr[mid]<arr[mid+1])
           {
               l=mid+1;
           }
           else 
           {
               h=mid;
           }
          
       }
       return 0;
    }
};