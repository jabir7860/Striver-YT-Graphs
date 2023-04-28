class Solution
{
    private : 
    void dfs(int node,vector<int> adj[],stack<int>&st,vector<int>&vis) 
    {
        vis[node]=1; 
        for(auto i:adj[node]) 
        {
            if(!vis[i]) 
            {
                dfs(i,adj,st,vis); 
            }
        }
        st.push(node); 
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int>vis(V,0); 
	   stack<int>st; 
	   for(int i=0;i<V;i++) 
	   {
	       if(!vis[i]) 
	       {
	           dfs(i,adj,st,vis); 
	       }
	   }
	   vector<int>ans; 
	   while(!st.empty()) 
	   {
	       ans.push_back(st.top()); 
	       st.pop(); 
	   }
	   return ans; 
	}
};
