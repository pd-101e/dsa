// below is bfs approach 
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<int> dx ={-2,-2,+2,+2,-1,-1,+1,+1};
    vector<int> dy ={-1,+1,+1,-1,-2,+2,-2,+2};
    
    bool issafe(int r , int c , int n )
    {
        return (r>=0 and c>=0 and r<n and c<n );
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    KnightPos[0]--;
		KnightPos[1]--;
		TargetPos[0]--;
		TargetPos[1]--;
	    vector<vector<int>>dist(N,vector<int>(N,-1));
        queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    dist[KnightPos[0]][KnightPos[1]]=0;
	    
	    while(!q.empty())
	    {
	        auto p = q.front();
	        int r = p.first;
	        int c = p.second;
	        q.pop();
	         if(r == TargetPos[0] and c == TargetPos[1] )
	                    {
	                        return dist[r][c];
	                    }
	        
	        for(int i = 0 ; i<8 ; i++)
	        {
	            int nr = r + dx[i];
	            int nc = c + dy[i];
	            
	            if(issafe(nr,nc,N))
	            {
	                if(dist[nr][nc]==-1 )
	                {
	                    dist[nr][nc] = dist[r][c] +1;
	                    q.push({nr,nc});
	                    if(nr == TargetPos[0] and nc == TargetPos[1] )
	                    {
	                        return dist[nr][nc];
	                    }
	                }
	            }
	        }
	    }
	    
	    return -1;
	}
};



// dfs approach
int dir[][2] = {{2, -1}, {2, 1}, {1, 2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}};

void util (int x, int y, vector<int>& target, int N,  int stepcount, vector<vector<int>> &visited) {
	
	if (x == target[0] && y == target[1]) {
		return;
	}
	
	for (int i=0; i<8; i++) {
		int newx = x + dir[i][0];
		int newy = y + dir[i][1];
		
		if (newx<=0 || newx>N || newy<=0 || newy>N) {
			continue;
		}
		
		if (stepcount + 1 < visited[newx-1][newy-1]) {
			visited[newx-1][newy-1] = stepcount+1;
			util(newx, newy, target, N, stepcount+1, visited);
		}
	}
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	
	vector<vector<int>> visited(N);
	for (int i=0; i<N; i++) {
		visited[i] = vector<int> (N, INT_MAX);
	}
	util (KnightPos[0], KnightPos[1], TargetPos, N, 0, visited);
	
	// return result;
	return visited[TargetPos[0]][TargetPos[1]];
}
