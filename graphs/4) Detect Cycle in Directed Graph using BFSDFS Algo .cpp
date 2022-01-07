// dfs approach
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



// bfs approach

class Solution{
  
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // bfs approach
        // kahn's algo
        
        
        vector<int>indegree(V,0);
        for(int i = 0 ; i<V ; i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        
        queue<int>q;
        for(int i = 0 ; i<V ; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count= 0 ;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto x:adj[curr])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
            
            
            count++;
        }
        if(count != V)
        {
            return true;// cycle exist
        }
        return false;
        
    }
};
  
};
