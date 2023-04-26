class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        queue<pair<int,int>>q; 
        for(int i=0;i<n;i++) 
        {
            if(grid[i][0]==1) q.push({i,0}); 
            if(grid[i][m-1]==1) q.push({i,m-1}); 
        }
        for(int j=0;j<m;j++) 
        {
            if(grid[0][j]==1) q.push({0,j}); 
            if(grid[n-1][j]==1) q.push({n-1,j}); 
        }
        int delrow[]={-1,0,+1,0}; 
        int delcol[]={0,+1,0,-1}; 
        vector<vector<bool>>vis(n,vector<bool>(m,0)); 
        // BFS 
        while(!q.empty()) 
        {
            int row=q.front().first; 
            int col=q.front().second; 
            q.pop(); 
            vis[row][col]=1; 
            for(int i=0;i<4;i++) 
            {
                int nrow=row+delrow[i]; 
                int ncol=col+delcol[i]; 
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]) 
                {
                    q.push({nrow,ncol}); 
                }
            }
            
        }
        int count=0; 
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++) 
            {
                if(grid[i][j]==1 && !vis[i][j]) count++; 
            }
        }
        return count; 
    }
};
