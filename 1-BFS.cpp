// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph 

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // visited array 
        int vis[V+1]={0}; 
        queue<int>q; 
        q.push(0); 
        // initailly the starting element is 0; 
        vector<int>ans; 
        //  adj matrix contains 
        // 0- 1 2 3  
        // 1- 
        // 2- 4 
        vis[0]=1; 
        while(!q.empty())
        {
            int node=q.front(); 
            q.pop(); 
            ans.push_back(node); 
            for(auto i:adj[node])
            {
                if(!vis[i]) 
                {
                    vis[i]=1; 
                    q.push(i); 
                }
            }
        }
        return ans; 
    }
