//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
    {
         vector<int>adj[V]; 
	    for(auto i:prerequisites) 
	    {
	        adj[i[1]].push_back(i[0]); 
	    }
	    vector<int>InD(V,0); 
	    for(int i=0;i<V;i++) 
	    {
	        for(auto it:adj[i]) 
	        {
	            InD[it]++; 
	        }
	    }
	    queue<int>q; 
	    vector<int>topo; 
	    for(int i=0;i<V;i++) 
	    {
	        if(InD[i]==0) q.push(i); 
	    }
	    while(!q.empty()) 
	    {
	        int node=q.front(); 
	        q.pop(); 
	        topo.push_back(node); 
	        for(auto it:adj[node]) 
	        {
	            InD[it]--; 
	            if(InD[it]==0) q.push(it); 
	        }
	    }
	    if(topo.size()==V) return topo; 
	    else return {}; 
    }
};
