class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        queue<int>q;
        q.push(0);
         res.push_back(0);
        bool visited[V];
        
        for(int i = 0 ; i<V; i++)
        {
            visited[i] = false;
        }
        visited[0] =true;
        
        while(!q.empty())
        {
            int p = q.front();
           
            q.pop();
            for(auto x:adj[p])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    q.push(x);
                    res.push_back(x);
                }
                
            }
            
        }
        return res;
    }
};
