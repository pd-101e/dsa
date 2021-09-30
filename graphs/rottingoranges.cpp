class Solution {
public:
    
    bool isvalid(int r , int c ,int m , int n)
    {
        return (r>=0 and c>=0 and r<m and c<n );
    }
    
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,1,0,-1};
        
        int m = mat.size();
        int n = mat[0].size();
        if(m==0) return {};
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,-1));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
                
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
                int nr = r+ dx[i];
                int nc = c + dy[i];
                if(isvalid(nr,nc,m,n))
                {
                    if(mat[nr][nc]==1 and dist[nr][nc]==-1)
                    {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
            
        }
        
        return dist;
    }
};
