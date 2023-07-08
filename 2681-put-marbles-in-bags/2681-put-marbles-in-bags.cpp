class Solution {
public:
   long long putMarbles(vector<int>& weights, int k) {
    #define lli long long 
        multiset<lli >ms;
        lli n=weights.size();
        for(int i=0;i<n-1;i++)
        {
            ms.insert(weights[i]+weights[i+1]);
        }
        for(auto c:ms)
        {cout<<c<<" "<<endl;}
       
        lli mn=weights[0]+weights[n-1];
        lli mx=weights[0]+weights[n-1];
         auto it = ms.begin();
    for (lli i = 0; i < k-1 && it != ms.end(); ++i, ++it) {
        mn+=*it;
    }
       auto rit = ms.rbegin();  // Obtain the reverse iterator pointing to the last element
    for (lli i = 0; i < k-1 && rit != ms.rend(); ++i, ++rit) {
        mx+=*rit;
    }
    
    return mx-mn;
    }
};