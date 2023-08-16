Dijktra is implemeted by 

1) QUEUE 2) PRORITY QUEUE 3) SET 

===============================
  1)QUEUE IMPLEMENTATION 
==============================
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        queue<pair<int,int>>q; 
        vector<int>dist(V,1e9); 
        dist[S]=0; 
        // from source to all the nodes in graph; 
        q.push({S,0}); 
        while(!q.empty()) 
        {
             int node=q.front().first; 
             int dis=q.front().second; 
             q.pop(); 
             for(auto it:adj[node]) 
             {
                 int AdjNode=it[0]; 
                 int AdjDist=it[1]; 
                 if(dist[AdjNode] > dis+AdjDist)
                 {
                     dist[AdjNode]=dis+AdjDist; 
                     q.push({AdjNode,dist[AdjNode]}); 
                 }
             }
        }
        return dist; 
    }
TC : O(N) SC : O(N) 
============================================================
2) PRORITY QUEUE IMPELEMENATTION
============================================================
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int>dist(V,1e9); 
        dist[S]=0; 
        // from source to all the nodes in graph; 
        q.push({S,0}); 
        while(!q.empty()) 
        {
             int node=q.top().first; 
             int dis=q.top().second; 
             q.pop(); 
             for(auto it:adj[node]) 
             {
                 int AdjNode=it[0]; 
                 int AdjDist=it[1]; 
                 if(dist[AdjNode] > dis+AdjDist)
                 {
                     dist[AdjNode]=dis+AdjDist; 
                     q.push({AdjNode,dist[AdjNode]}); 
                 }
             }
        }
        return dist; 
    }
TC : O(N*LOG N) SC :O(N) 
========================================================
3) SET IMPLEMENATION 
=======================================================
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        
        set<pair<int,int>> st;
        
        st.insert({0,S});
        dist[S] = 0;
        
        
        while(!st.empty()){
            auto s = *(st.begin());
            int node = s.second;
            int d = s.first;
            
            st.erase(s);
            
            for(auto x : adj[node]){
                int adjNode = x[0];
                int adjDist = x[1];
                if(dist[adjNode] > (d + adjDist)){
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + adjDist;
                    st.insert({dist[adjNode],adjNode}); 
                } 
            }
        }
        
        return dist;
    } 
===========================================
  TC : O(V^2) SC :O(N) 
