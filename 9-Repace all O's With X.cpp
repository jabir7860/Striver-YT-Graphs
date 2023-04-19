class Solution{
private: 
void dfs(int row,int col,vector<vector<char>>&mat,vector<vector<int>>&vis,int delR[],int delC[],int n,int m) 
{
    vis[row][col]=1; 
    for(int i=0;i<4;i++) 
    {
        int Nrow=row+delR[i]; 
        int Ncol=col+delC[i]; 
        if(Nrow>=0 && Ncol>=0 && Nrow<n && Ncol<m && !vis[Nrow][Ncol] && mat[Nrow][Ncol]=='O') 
        {
            dfs(Nrow,Ncol,mat,vis,delR,delC,n,m); 
        }
    }
}
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // Checking For Boundaries so that they are not surrounded by X. 
        // first row and last row 
        int delR[]={-1,0,+1,0}; 
        int delC[]={0,+1,0,-1}; 
        vector<vector<int>>vis(n,vector<int>(m,0));  
        for(int j=0;j<m;j++) 
        {
            if(mat[0][j]=='O' && !vis[0][j]) 
            {
                dfs(0,j,mat,vis,delR,delC,n,m); 
                // first row 
            }
            if(mat[n-1][j]=='O' && !vis[n-1][j]) 
            {
                dfs(n-1,j,mat,vis,delR,delC,n,m); 
                // last row. 
            }
        }
        for(int i=0;i<n;i++) 
        {
            if(mat[i][0]=='O' && !vis[i][0]) 
            {
                dfs(i,0,mat,vis,delR,delC,n,m); 
                // first column; 
            }
            if(mat[i][m-1]=='O' && !vis[i][m-1]) 
            {
                dfs(i,m-1,mat,vis,delR,delC,n,m);  
            }
        }
        for(int i=0;i<n;i++) 
        { 
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && mat[i][j]=='O') 
                {
                    mat[i][j]='X'; 
                }
            }
        }
        return mat; 
    }
};
