bool isBipartite(int V, vector<int>adj[]){
	    queue<int>q; 
	    q.push(0); 
	    vector<int>col(V,-1);   
	    col[0]=0; 
	    while(!q.empty()) 
	    {
	        int node=q.front(); 
	        q.pop(); 
	        for(auto i:adj[node]) 
	        {
	            // not colored. 
	            if(col[i]==-1)  
	            {
	                col[i]=!col[node]; 
	                q.push(i); 
	            }
	            // colored 
	            else if(col[i]==col[node]) return 0; 
	        }
	    }
	    return 1; 
	}
