class Solution {
public:
   string addBinary(string a, string b) {

      int lengthA=a.size();
      int lengthB=b.size();
    if (lengthA < lengthB) {
        a = std::string(lengthB - lengthA, '0') + a;
    } else if (lengthA > lengthB) {
        b = std::string(lengthA - lengthB, '0') + b;
    }
      reverse(a.begin(),a.end());
      reverse(b.begin(),b.end());
      int s=0;
      int c=0;
      string ans;
      for(int i=0;i<max(a.size(),b.size());i++)
      {
        int x=a[i]-48;
        int y=b[i]-48;
        s=x ^y^c;
        c= (x&y) |(x&c)|(c&y);
        ans+=((char)s+48);
      } 
      if(c) ans+=((char)c+48);
       reverse(ans.begin(),ans.end());
       return ans; 
    } 
};