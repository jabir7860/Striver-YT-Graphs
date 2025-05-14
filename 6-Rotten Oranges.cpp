https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size(); 
        int vis[n][m]; 
        int one=0; 
        queue<pair<pair<int,int>,int>>q; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2; 
                    q.push({{i,j},0}); 
                }
                else
                {
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) one++; 
            }
        }
        int tim=0; 
        int ROW[]={-1,0,+1,0}; 
        int COL[]={0,+1,0,-1}; 
        int ONE=0; 
        while(!q.empty())
        {
            int row=q.front().first.first; 
            int col=q.front().first.second; 
            int t=q.front().second; 
            tim=max(tim,t); 
            q.pop(); 
            for(int i=0;i<4;i++)
            {
                int nrow=row+ROW[i]; 
                int ncol=col+COL[i]; 
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    grid[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                    {
                        ONE++; 
                        q.push({{nrow,ncol},t+1}); 
                        vis[nrow][ncol]=2; 
                    }
            }
        }
        if(one!=ONE) return -1; 
        return tim;
    }
};
