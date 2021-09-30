class Solution {
public:
    
    bool isvalid(int r , int c ,int m , int n)
    {
        return (r>=0 and c>=0 and r<m and c<n );
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
        
        int m = grid.size();
        int n = grid[0].size();
        if(m==0)
        {
            return {};
        }
        
        
        
        vector<vector<int>>dist(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        
        bool flag = false;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    dist[i][j] = 2;
                     flag = true;
                }
                if(grid[i][j]==0)
                {
                    dist[i][j] = 0;
                }
                
            }
        }
       if(flag == false)
       {
           if(m==1)
        {
            for(int i = 0 ; i<n ; i++)
            {
                if(grid[0][i]==1)
                {
                    return -1;
                }
            }
            return 0;
        }
        
         if(n==1)
        {
            for(int i = 0 ; i<m ; i++)
            {
                if(grid[i][0]==1)
                {
                    return -1;
                }
            }
            return 0;
        }
       }
        
        while(!q.empty())
        {
            
            auto p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();
            for(int i = 0 ; i<4 ; i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if(isvalid(nr,nc,m,n))
                {
                    if(grid[nr][nc] == 1 and dist[nr][nc] == -1 )
                    {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
                
            }
            
            
            
        }
        // for(int i = 0 ; i<m ; i++)
        // {
        //     for(int j = 0 ; j<n ; j++)
        //     {
        //         cout<<dist[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
        
        int ans = 0;
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(dist[i][j] == -1)
                {
                    return -1;
                }
                ans = max(dist[i][j],ans);
            }
        }
        
        //cout<<endl<<ans<<endl;
        return ans - 2 ;
    }
};
