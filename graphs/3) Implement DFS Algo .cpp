public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(vector<int>adj[] , int s , bool visited[] , vector<int>&res)
    {
        visited[s]=true;
        res.push_back(s);
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            {
                dfs(adj,x,visited,res);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool visited[V];
        vector<int>res;
        for(int i = 0 ; i<V ; i++)
        {
            visited[i] = false;
        }
        for(int i = 0 ; i<V ; i++)
        {
            if(visited[i]==false)
            dfs(adj,i,visited,res);
        }
        return res;
        
    }
};
