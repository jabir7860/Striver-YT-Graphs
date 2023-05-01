// STRIVER APPRAOCH 
// User function Template for C++
class Solution {
  private : 
  void topo(int node,vector<pair<int,int>>adj[],stack<int>&st,vector<int>&vis) 
  {
      vis[node]=1; 
      for(auto i:adj[node]) 
      {
          if(!vis[i.first]) 
          {
              topo(i.first,adj,st,vis); 
          }
      }
      st.push(node); 
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N]; 
        for(int i=0;i<M;i++) 
        {
            int node=edges[i][0]; 
            int to=edges[i][1]; 
            int d=edges[i][2]; 
            adj[node].push_back({to,d}); 
        }
        // topo sort; 
        stack<int>st; 
        vector<int>vis(N,0);
        for(int i=0;i<M;i++) 
        {
            if(!vis[i]) 
            {
                topo(i,adj,st,vis); 
            }
        }
        vector<int>dist(N,1e9);
        dist[0]=0; 
        while(!st.empty()) 
        {
            int node=st.top(); 
            st.pop(); 
            for(auto i:adj[node]) 
            {
                int v=i.first; 
                int w=i.second; 
                if(dist[node]+w <dist[v]) 
                {
                    dist[v]=dist[node]+w; 
                }
            }
        }
        return dist; 
    }
}; 

// MAIN SOLUTION  
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         // code here
        vector<pair<int,int>>adj[N];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dist(N,1e9);
        queue<int>q;
        q.push(0);
        dist[0]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                int outgoing=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[outgoing])
                {
                    dist[outgoing]=dist[node]+wt;
                    q.push(outgoing);
                    
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};
