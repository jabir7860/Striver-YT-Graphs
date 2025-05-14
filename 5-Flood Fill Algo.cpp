https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
class Solution {
public:
    void bfs(int i,int j,int color,vector<vector<int>>&ans,vector<vector<int>>&vis,int oldcolor)
    {
        queue<pair<int,int>>q; 
        q.push({i,j}); 
        vis[i][j]=1; 
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()) 
        {
            int row=q.front().first; 
            int col=q.front().second; 
            q.pop(); 
            ans[row][col]=color; 
            for(int k=0;k<4;k++) 
            {
                int newrow=row+dx[k]; 
                int newcol=col+dy[k];
                if(newrow >= 0 && newrow < ans.size() && newcol >= 0 && newcol < ans[0].size() && vis[newrow][newcol] == 0 && ans[newrow][newcol] == oldcolor) 
                {
                vis[newrow][newcol] = 1; 
                cout << "JABIR" << newrow << " " << newcol << endl; 
                q.push({newrow, newcol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) { 
        int m=image.size(); 
        int n=image[0].size(); 
        int oldcolor=image[sr][sc]; 
        vector<vector<int>>ans=image; 
        vector<vector<int>>vis(m,vector<int>(n,0)); 
        bfs(sr,sc,color,ans,vis,oldcolor); 
        return ans; 
    }
};
