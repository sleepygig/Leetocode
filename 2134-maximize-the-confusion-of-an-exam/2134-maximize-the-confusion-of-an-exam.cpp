class Solution {
public:
     int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0;
        int j=i;
        int n=answerKey.size();
        int ans =-2;
        int cT=0;
        int cF=0;
        while(j<n)
        {
            if(answerKey[j]=='F')
            {
                ans=max(ans,j-i+1); 
                j++;
            }
            else 
            {
                cT++;
                while(cT>k)    
                {
          
                    if(answerKey[i]=='T') cT--;
                    i++;
                    ans=max(ans,j-i+1); 
                }            
                j++;
            }

        }
        ans=max(ans,j-i); 
         i=0;
         j=i;
             while(j<n)
        {
            if(answerKey[j]=='T')
            {
                ans=max(ans,j-i+1); 
                j++;
            }
            else 
            {
                cF++;
             
                while(cF>k)    
                { 
                    if(answerKey[i]=='F') cF--;
                    i++;
                    ans=max(ans,j-i+1); 
                }            
                j++;
            }
        }
        ans=max(ans,j-i); 
        return ans ;
     }
};