vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
         vector<pair<int,int>> adj[n+1];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        
        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        dist[1] = 0;
        pq.push({0,1});
        vector<int> parent(n+1,-1);
        
        for(int i = 1; i <= n; i++){
            parent[i] = i; 
        }
        
        while(!pq.empty()){
            
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                
                int adjNode = it.first;
                int edW = it.second;
                
                if(dist[adjNode] > weight + edW){
                    
                    dist[adjNode] = weight + edW;
                    pq.push({weight + edW,adjNode});
                    parent[adjNode] = node;
                    
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        vector<int> ans;
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
