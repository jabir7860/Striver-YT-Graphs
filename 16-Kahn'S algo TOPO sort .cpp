
// BFS TECHNIQUE 
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // Find InDegree of Each and every node in given graph.
	    vector<int>InDegree(V,0); 
	    for(int i=0;i<V;i++) 
	    {
	        for(auto it:adj[i]) 
	        {
	            InDegree[it]++;  
	        }
	    }
	    queue<int>q; 
	    for(int i=0;i<V;i++) 
	    {
	        if(InDegree[i]==0) q.push(i); 
	    }
	    vector<int>ans; 
	    while(!q.empty()) 
	    {
	        int node=q.front(); 
	        q.pop(); 
	        ans.push_back(node); 
	        for(auto it:adj[node]) 
	        {
	            InDegree[it]--; 
	            if(InDegree[it]==0) q.push(it); 
	        }
	    }
	    return ans; 
	}
};
