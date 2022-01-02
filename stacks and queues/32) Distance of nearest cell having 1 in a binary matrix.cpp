class Solution
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<int> dx = {1,-1,0,0};
	    vector<int> dy = {0,0,-1,1};
	    queue<pair<int,int>>q;
	    vector<vector<int>>dist(n,vector<int> (m));
	    for(int i = 0 ; i<n ; i++)
	    {
	        for(int j = 0 ; j<m ; j++)
	        {
	            dist[i][j] = INT_MAX;
	            if(grid[i][j])
	            {
	                q.push({i,j});
	                dist[i][j] = 0 ;
	            }
	        }
	    
	        
	    }
	    
	    int distance = 0 ;
	    while(!q.empty())
	    {
	        int size = q.size();
	        distance++;
	        for(int i = 0 ; i<size ; i++)
	        {
	            auto temp = q.front();
	            int x = temp.first;
	            int y =temp.second;
	            q.pop();
	            for(int i = 0 ; i<4 ; i++)
	            {
	                int nx = x + dx[i];
	                int ny = y + dy[i];
	                if(nx<0 || nx >=n || ny<0 || ny>=m)
	                continue;
	                
	                if(dist[nx][ny] > distance)
	                {
	                    dist[nx][ny] = distance;
	                    q.push({nx,ny});
	                }
	                
	                
	            }
	            
	        }
	    }
	    return dist;
	    
	    
	}
};
