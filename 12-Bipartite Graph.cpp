// BRUTE FORCE
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
TC :O(N) 
SC :O(N) 
	
class Solution {
// EASY BFS SOLUTION IN C++
public:

    bool bfs(int node,vector<int> &vis,vector<int>&col,vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        col[node] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:adj[node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                    if(col[node]==0)
                        col[i] = 1;
                    else col[i] = 0;
                }
                else if(col[node] == col[i]) return 0;
            }
        }
        return 1;
    }
	bool isBipartite(int V,vector<int>adj[]){
	    vector<int> vis(V,0);
	    vector<int> col(V,-1);
	    for(int i =0;i<V;i++)
	        if(!vis[i]){
	            bool b = bfs(i,vis,col,adj);
	            if(b==0) return 0;
	        }
	        
	    return 1;
	}

}; 

//  EASY DFS SOLUTION 
 bool dfs(int coll,int node,vector<vector<int>>&adj,vector<int>&col,int n) 
    {
        col[node]=coll;  
        for(auto i:adj[node]) 
        {
            if(col[i]==-1) 
            {
                if(dfs(!coll,i,adj,col,n)==false) return 0; 
            }
            else if(col[i]==col[node]) 
            {
                return 0;
            }
        }
        return 1; 
    }
    bool isBipartite(vector<vector<int>>&adj ) {
        int n=adj.size(); 
        vector<int>col(n,-1); 
        for(int i=0;i<n;i++) 
        {
            if(col[i]==-1) 
            {
                if(dfs(0,i,adj,col,n)==false) return 0;  
            }

        }
        return 1; 
    }
	
