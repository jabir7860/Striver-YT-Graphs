
IMPLEMENTED USING QUEUE

 int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        
        vector<pair<int,int>>adj[n]; 
        for(auto i:flights) 
        {
            adj[i[0]].push_back({i[1],i[2]}); 
        }
        queue<pair<int,pair<int,int>>>q; 
        vector<int>dist(n,1e9); 
        dist[src]=0; 
        q.push({0,{src,0}});
        while(!q.empty()) 
        {
            auto it=q.front(); 
            q.pop(); 
            int stops=it.first; 
            int node=it.second.first;
            int dis=it.second.second; 
            if(stops>K) 
                continue;  
            for(auto itr:adj[node]) 
            {
                int adjnode=itr.first; 
                int adjdist=itr.second; 
                if(dis+adjdist < dist[adjnode] && stops<=K) 
                {
                    dist[adjnode]=dis+adjdist; 
                    q.push({stops+1,{adjnode,dist[adjnode]}}); 
                }
            }
        }
        if(dist[dst]==1e9) return -1; 
        return dist[dst]; 
    }
