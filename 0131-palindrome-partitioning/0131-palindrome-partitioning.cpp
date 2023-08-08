class Solution {
public:
bool isPalindromic(const std::string& str, int l,int r) {
    int left = l;
    int right = r;

    while (left < right) {
        // Convert characters to lowercase for case-insensitive comparison
        char leftChar = std::tolower(str[left]);
        char rightChar = std::tolower(str[right]);

        if (leftChar != rightChar) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}
int fs(string str,int i,int j,int n,vector<vector<string>>&ans,vector<string>&tp)
		{
			if(j==n-1 )
			{
				if(isPalindromic(str,i,j)) 
				{
					tp.push_back(str.substr(i, j - i + 1));
					ans.push_back(tp);
					tp.pop_back	();
					return 1;
				}
				else return 0;
			}
			if(isPalindromic(str,i,j))
			{
				tp.push_back(str.substr(i, j - i + 1));
				int l=fs(str,j+1,j+1,n,ans,tp);
				tp.pop_back	();
				int r=fs(str,i,j+1,n,ans,tp);    //lgaa rha
				return l+r;
				
			}
			else{
				int l=fs(str,i,j+1,n,ans,tp);
				int r=0;
				return l+r;
			}
			return 0;
			
		}

  vector<vector<string>> partition(string s) {
	  vector<vector<string>>ans;
	 vector<string>tp;
	 fs(s,0,0,s.size(),ans,tp);
	 return ans;

        
    }
};