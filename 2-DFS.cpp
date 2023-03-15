// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph

void dfs(int node,vector<int>adj[],int vis[],vector<int>&ans)
    {
        vis[node]=1; 
        ans.push_back(node); 
        for(auto i:adj[node]) 
        {
            if(!vis[i]) 
            {
                dfs(i,adj,vis,ans); 
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans; 
        int vis[V+1]={0}; 
        dfs(0,adj,vis,ans); 
        return ans; 
    }
