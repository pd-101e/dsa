class Solution{
    public:
    vector<string>ans;
    
    void dfs(int x, int y , vector<vector<int>> &matrix , int n ,string res)
    {
        if(x>=n or y>=n or x<0 or y<0 or matrix[x][y]==0 )
        return ;
    
        if(x==n-1 and y==n-1)
        {
            ans.push_back(res);
            return ;
        }
        matrix[x][y]=0;
        dfs(x-1,y,matrix,n,res + "U");
        dfs(x+1,y,matrix,n,res + "D");
        dfs(x,y-1,matrix,n,res + "L");
        dfs(x,y+1,matrix,n,res + "R");
        matrix[x][y]=1;
        return;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
            if(m[0][0]==0)
            return ans;
        dfs(0,0,m,n,"");
        sort(ans.begin(), ans.end());
        return ans;
    }
    
};

    
