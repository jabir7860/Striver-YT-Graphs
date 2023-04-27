bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&Pvis,vector<int>&check)  
    {
        vis[node]=1; 
        Pvis[node]=1; 
        for(auto i:adj[node]) 
        {
            if(!vis[i]) 
            {
                if(dfs(i,adj,vis,Pvis,check)==true) 
                {   
                    check[node]=0; 
                    return 1;
                }
            }
            else if(vis[i]==1 && Pvis[i]==1) 
            {
                check[node]=0; 
                return 1; 
            }
        }
        check[node]=1; 
        Pvis[node]=0; 
        return 0; 
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0); 
        vector<int>Pvis(V,0);
        vector<int>check(V,0); 
        vector<int>ans; 
        for(int i=0;i<V;i++) 
        {
            if(!vis[i]) 
            {
                dfs(i,adj,vis,Pvis,check); 
            }
        }
        for(int i=0;i<V;i++) 
        {
            if(check[i]==1) ans.push_back(i); 
        }
        return ans;
    }
