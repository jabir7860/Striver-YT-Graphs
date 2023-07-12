https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size(); 
	    int m=grid[0].size(); 
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    vector<vector<int>>vis(n,vector<int>(m,0)); 
	    queue<pair<pair<int,int>,int>>q; 
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1) 
	            {
	                vis[i][j]=1; 
	                q.push({{i,j},0}); 
	            }
	            else
	            {
	                vis[i][j]=0; 
	            }
	        }
	    }
	      int delrow[] = {-1, 0, +1, 0}; 
	      int delcol[] = {0, +1, 0, -1}; 
	    while(q.empty()==false)
	    {
	        int row=q.front().first.first; 
	        int col=q.front().first.second; 
	        int dis=q.front().second;  
	        q.pop(); 
	        dist[row][col]=dis; 
	        for(int i=0;i<4;i++)
	        {
	            int nrow=row+delrow[i]; 
	            int ncol=col+delcol[i]; 
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0) 
	            {
	                vis[nrow][ncol]=1; 
	                q.push({{nrow,ncol},dis+1}); 
	            }
	        }
	    }
	    return dist; 
	}
