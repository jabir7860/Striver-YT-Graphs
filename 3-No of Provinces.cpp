https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1 

class Solution {
  public:
    void dfs(int i,vector<int>adj[],vector<int>&vis,vector<vector<int>>&ans) 
    {
        vis[i]=1; 
        queue<int>q; 
        q.push(i); 
        vector<int>temp; 
        while(!q.empty()) 
        {
            int node=q.front(); 
            q.pop(); 
            temp.push_back(node); 
            for(auto j:adj[node]) 
            {
                if(!vis[j]) 
                {
                    vis[j]=1;
                    q.push(j); 
                }
            }
        }
        sort(temp.begin(),temp.end()); 
        ans.push_back(temp); 
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>ans; 
        vector<int>adj[V]; 
        for(int i=0;i<edges.size();i++) 
        {
            adj[edges[i][0]].push_back(edges[i][1]); 
            adj[edges[i][1]].push_back(edges[i][0]); 

        }
        vector<int>vis(V,0); 
        int count=0; 
        for(int i=0;i<V;i++) 
        {
            if(!vis[i]) 
            {
                dfs(i,adj,vis,ans);
                count++; 
            }
        }
        cout<<"NO of Provisions : "<<count<<endl ;
        return ans; 
    }
};

TC : O(V+E)
