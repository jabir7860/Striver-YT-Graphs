https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
class Solution {
    private:
        void fun(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid)
        {
            int n=grid.size(); 
            int m=grid[0].size(); 
            vis[row][col]=1; 
            queue<pair<int,int>>q; 
            q.push({row,col}); 
            while(!q.empty())
            {
                int row=q.front().first; 
                int col=q.front().second;
                q.pop(); 
                for(int delrow=-1;delrow<=+1;delrow++)
                {
                    for(int delcol=-1;delcol<=+1;delcol++)
                    {
                        int nrow=row+delrow; 
                        int ncol=col+delcol; 
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'&& vis[nrow][ncol]==0)
                        {
                            vis[nrow][ncol]=1; 
                            q.push({nrow,ncol}); 
                        }
                    }
                }
            }
        }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        int cnt=0; 
        vector<vector<int>>vis(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0) 
                {
                    cnt++; 
                    fun(i,j,vis,grid); 
                }
            }
        }
        return cnt; 
    }
};
