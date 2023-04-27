 bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&Pvis) 
    {
        vis[node]=1; 
        Pvis[node]=1; 
        for(auto i:adj[node]) 
        {
            if(!vis[i]) 
            {
                if(dfs(i,adj,vis,Pvis)==true) return 1; 
            }
            else if(vis[i]==1 && Pvis[i]==1) 
            {
                return 1; 
            }
        }
        Pvis[node]=0; 
        return 0; 
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0); 
        vector<int>Pvis(V,0);
        for(int i=0;i<V;i++) 
        {
            if(!vis[i]) 
            {
                if(dfs(i,adj,vis,Pvis)==true) return 1; 
            }
        }
        return 0; 
    } 
