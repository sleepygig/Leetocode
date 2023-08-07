class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
void dfs1(vector<vector<int>>&vis,vector<vector<char>>& board, int sr,int sc)
{
        int m=vis.size();
        int n=vis[0].size();

        vis[sr][sc]=1;
        for(int i=0;i<4;i++)
        {
            int nr=sr+dr[i];
            int nc=sc+dc[i];
            if(nr>=0 and nr<m and nc>=0 and nc<n and
             board[nr][nc]=='O' and vis[nr][nc]==0)
            {
                vis[nr][nc]=1;
                dfs1(vis,board,nr,nc);
            }
        }
        return ;
}

void dfs2(vector<vector<int>>&vis,vector<vector<char>>& board, int sr,int sc)
{
        int m=vis.size();
        int n=vis[0].size();

        vis[sr][sc]=1;
        for(int i=0;i<4;i++)
        {
            int nr=sr+dr[i];
            int nc=sc+dc[i];
            if(nr>=0 and nr<m and nc>=0 and nc<n and
             board[nr][nc]=='O' and vis[nr][nc]==0)
            {
                vis[nr][nc]=1;
                board[nr][nc]='X';
                dfs2(vis,board,nr,nc);
            }
        }
        return ;
}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==0 or i==m-1 or j==0 or j==n-1 )
                {
                    if(!vis[i][j] and board[i][j]=='O')
                        dfs1(vis,board,i,j);
                }
                }
            }
              for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if( !vis[i][j] and board[i][j]=='X')
                    {
                        dfs2(vis,board,i,j);
                    }
                }
            }
        
    }
};