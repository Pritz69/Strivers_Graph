class Solution {
private :
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,vector<pair<int,int>>&vec,int row0,int col0)
    {
        vis[row][col]=1;
        
        vec.push_back({row-row0,col-col0});
        
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nr=row+delrow[i];
            int nc=col+delcol[i];
            if (nr>=0 && nr <n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1)
            {
                dfs(nr,nc,grid,vis,vec,row0,col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (vis[i][j]==0 && grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
