class Solution {
public:
  int fs(vector<int>v ,int size )
{
    int n=size;
    vector<pair<int,int>>nsl(n,{0,0});
    stack<int>st;
    for(int i=0;i<n;i++)
    {
      while(st.size() and v[st.top()]>=v[i]) st.pop();
      if(st.size()==0)  nsl[i].first=-1;
      else if(v[st.top()]<v[i]) nsl[i].first=st.top();  
      st.push(i);   
    }
    while(st.size()) st.pop();
      for(int i=n-1;i!=-1;i--)
    {
      while(st.size() and v[st.top()]>=v[i]) st.pop();
      if(st.size()==0)  nsl[i].second=n;
      else if(v[st.top()]<v[i]) nsl[i].second=st.top();     
      st.push(i);
    }
    int a=-5;
    for(int i=0;i<n;i++)
    {
        a=max(v[i]*(nsl[i].second-nsl[i].first-1),a);
    }
    return a;
}
   int maximalRectangle(vector<vector<char>>& matrix) {
  int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - 1 >= 0 && matrix[i][j] != '0') {
                ans[i][j] = 1 + ans[i - 1][j];
            } else {
                ans[i][j] = matrix[i][j] == '1' ? 1 : 0;

            }
        }
    }

 int a = -9;
for (int i = 0; i < m; i++) {  // Iterate over columns
    a = max(a, fs(ans[i], n));  // Pass the correct size 'n'
}

    return a;
       
    }
};