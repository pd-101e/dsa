class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int s , vector<int> adj[] , bool rest[] , bool visited[])
    {
        visited[s] = true;
        rest[s] = true;
        for(auto u:adj[s])
        {
            if(visited[u]==false)
            {
                if(dfs(u,adj,rest,visited))
                return true;
                
            }
            else if(rest[u]==true)
            return true;
        }
        rest[s]=false;
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool visited[V] ;
        bool rest[V];
        for(int i = 0 ; i<V; i++)
        {
            visited[i] = false;
            rest[i] = false;
        }
        for(int i = 0 ; i<V ; i++)
        {
            if(visited[i]== false)
            {
                if(dfs(i,adj,rest,visited))
                return true;
            }
        }
        return false;
        
    }
};
