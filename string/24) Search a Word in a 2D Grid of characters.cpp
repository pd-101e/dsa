// correct approach
class solution{
public:
vector<vector<int>>ans;

vector<int>dx = {1,-1,-1,1,-1,1,0,0};
vector<int>dy = {1,-1,1,-1,0,0,-1,1};

bool solve(int i,int j,vector<vector<char>>&grid,string &s,int index,int n,int m,int size)
{
     // Search word in all 8 directions starting from (row,col)
     int len = s.length();
    for(int k = 0 ; k<8 ; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        
        int idx;
	 
	        // First character is already checked, match remaining
	        // characters
	        for (idx = 1; idx < len; idx++)
	        {
	            // If out of bound break
	            if (nx >= n || nx < 0 || ny >= m || ny < 0)
	                break;
	 
	            // If not matched,  break
	            if (grid[nx][ny] != s[idx])
	                break;
	 
	            //  Moving in particular direction
	            nx += dx[k], ny += dy[k];
	        }
	 
	        // If all character matched, then value of must
	        // be equal to length of word
	        if (idx == len)
	            return true;
        
    }
    return false;
    
    
}

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int size = word.length();
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    for(int i = 0 ; i<n ; i++)
	    {
	        for(int j = 0 ; j<m ; j++)
	        {
	            if(grid[i][j] == word[0])
	            if(solve(i,j,grid,word,0,n,m,size))
	            {
	                ans.push_back({i,j});
	            }
	        }
	    }
	    
	    return ans;
	}
};




// my wrong approoach
/*
whats wrong see
your code checks for a word in all possibe ways from a starting pos,
not just in the 8 directions
if we find the word in one direction we have to move is that direction only
*/
clsss solution
{
public:
vector<vector<int>>ans;

vector<int>dx = {1,-1,-1,1,-1,1,0,0};
vector<int>dy = {1,-1,1,-1,0,0,-1,1};

bool solve(int i,int j,vector<vector<char>>&grid,string &s,int index,int n,int m,int size)
{
    if(index == size)
    {
        return true;
    }
    
    if(i>=0 and j>=0 and i<n and j<m and grid[i][j]==s[index])
    {
    
    char temp = s[index];
    grid[i][j] = '0';
    
    for(int k = 0 ; k<8 ; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(solve(nx,ny,grid,s,index+1,n,m,size))
        {
            return true;
        }
    }
    grid[i][j] = temp;
    
    }
    return false;
    
}

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int size = word.length();
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    for(int i = 0 ; i<n ; i++)
	    {
	        for(int j = 0 ; j<m ; j++)
	        {
	            if(grid[i][j] == word[0])
	            if(solve(i,j,grid,word,0,n,m,size))
	            {
	                ans.push_back({i,j});
	            }
	        }
	    }
	    if(ans.size() == 0)
	    {
	        
	        return ans;
	    }
	    return ans;
	}
};
