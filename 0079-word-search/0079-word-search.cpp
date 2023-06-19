class Solution {
public:
    int dr[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[8] = {0, 1, 0, -1, -1, 1, -1, 1};
  bool dfs(vector<vector<int>>&vis ,string word,
  int sr,int sc,int pos,vector<vector<char>>& board)
  {
     int m=board.size();
      int n=board[0].size();
    vis[sr][sc]=1;
    if(pos==word.size()) return true;
    for(int i=0;i<4;i++)
    {
       int nr=sr+dr[i];
       int nc=sc+dc[i];
       if(nr>=0 and nr<m and nc>=0 and nc<n)
       {
        if(!vis[nr][nc] and board[nr][nc]==word[pos])
        {
          //  print2d(vis,m,n);
          if(dfs(vis,word,nr,nc,pos+1,board)) 
          {vis[nr][nc]=0;
          return true;}
        }
       }
    }
    vis[sr][sc]=0;
    return false;

  }
  bool exist(vector<vector<char>>& board, string word) {
      int m=board.size();
      int n=board[0].size();
        vector<vector<int>>vis(m,vector<int> (n,0));
        bool y=false;
        for(int i=0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
              if(vis[i][j]==0 and word[0]==board[i][j])
              {
               
                y=y or dfs(vis,word,i,j,1,board);
              }
          }
        }
        return y;
        
    }
};