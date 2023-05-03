class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N]; 
        for(auto it:edges) 
        {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        queue<int>q; 
        vector<int>dist(N,1e9); 
        dist[src]=0; 
        q.push(src); 
        while(!q.empty()) 
        {
            int node=q.front(); 
            q.pop(); 
            for(auto i:adj[node]) 
            {
                if(dist[i]>dist[node]+1) 
                {
                    dist[i]=dist[node]+1; 
                    q.push(i); 
                }
            }
        }
        vector<int>ans(N,-1); 
        for(int i=0;i<N;i++) 
        {
            if(dist[i]!=1e9) 
            {
                ans[i]=dist[i]; 
            }
        }
        return ans; 
    }
};
