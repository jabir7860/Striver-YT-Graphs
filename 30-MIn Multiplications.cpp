 int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q; // num , steps
        q.push({start,0}); 
        vector<int>dist(100000,1e9); 
        dist[start]=0; 
        while(!q.empty()) 
        {
            int num=q.front().first; 
            int steps=q.front().second; 
            q.pop(); 
            for(auto it:arr) 
            {
                int newnum=(num*it)%100000; 
                if(dist[newnum] > steps+1) 
                {
                     if(newnum==end) return steps+1;
                     dist[newnum]=steps+1; 
                     q.push({newnum,steps+1}); 
                }
            }
            
        }
        return -1; 
    }
