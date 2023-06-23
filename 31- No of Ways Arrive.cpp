int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        int mod=(int)(1e9+7);
        while(!pq.empty())
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                int wt=i.second;
                int child=i.first;
                if(dist[child]>(long long)time+wt)
                {
                    dist[child]=(long long)time+wt;
                    ways[child]=ways[node];
                    pq.push({dist[child],child});
                }
                else if(dist[child]==time+wt)
                {
                    ways[child]=(ways[child]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
