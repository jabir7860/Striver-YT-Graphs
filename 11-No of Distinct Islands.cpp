class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,
    set<vector<pair<int,int>>>&st,vector<pair<int,int>>&vec,int row0,int col0) 
    {
        vis[row][col]=1; 
        vec.push_back({row-row0,col-col0}); 
        int delrow[]={-1,0,+1,0}; 
        int delcol[]={0,-1,0,+1}; 
        int n=grid.size(); 
        int m=grid[0].size(); 
        for(int i=0;i<4;i++) 
        {
            int nrow=row+delrow[i]; 
            int ncol=col+delcol[i]; 
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1) 
            {
                dfs(nrow,ncol,grid,vis,st,vec,row0,col0); 
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        set<vector<pair<int,int>>>st; 
        vector<vector<int>>vis(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++) 
             {
                 if(grid[i][j]==1 && vis[i][j]==0) 
                 {
                     vector<pair<int,int>>vec; 
                     dfs(i,j,grid,vis,st,vec,i,j); 
                     st.insert(vec); 
                 }
             }
         }
         return st.size(); 
    }
};
