https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

private:
    void dfs(int node,vector<int>adjList[],int vis[])
    {
        vis[node]=1; 
        for(auto i:adjList[node])
        {
            if(!vis[i])
            {
                dfs(i,adjList,vis); 
            }
        }
    }
    public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // convert given 2D adj to 1D adj 
        vector<int>adjList(V); 
        for(int i=0;i<=V;i++)
        {
            for(int j=0;j<=V;j++)
            {
                if(i!=j && adj[i][j]==1)
                {
                    adjList[i].push_back(j); 
                    adjList[j].push_back(i); 
                }
            }
        }
        int vis[V+1]={0}; 
        int count=0; 
        for(int i=0;i<=V;i++)
        {
            if(!vis[i])
            {
                count++; 
                dfs(i,adjList,vis); 
            }
        }
        return count; 
    }
