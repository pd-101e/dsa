public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int s, vector<int> adj[] , bool visited[], int parent)
    {
        visited[s] = true;
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            {
                if(dfs(x,adj,visited,s)==true)
                return true;
            }
            else if(x!=parent)
                 return true;
        }
        return false;
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool visited[V];
        for(int i = 0 ; i<V ; i++)
        {
            visited[i]=false;
        }
        
        for(int i = 0 ; i<V ;i++)
        {
            if(visited[i]==false)
            if( dfs(i,adj,visited,-1)==true)
                return true;
        }
        return false;
    }
};
