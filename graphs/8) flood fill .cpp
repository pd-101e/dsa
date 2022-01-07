class Solution {
public:
    
   
    
    void dfs(int r, int c , vector<vector<int>>&dp , int temp,int n,int m,int x)
    {
        if(r < 0 || c < 0 || r >= n || c >= m || dp[r][c] == temp || dp[r][c] != x) 
            return;
        dp[r][c] = temp;
        
         
                dfs(r-1,c,dp,temp,n,m,x);
                dfs(r+1,c,dp,temp,n,m,x);
                dfs(r,c-1,dp,temp,n,m,x);
                dfs(r,c+1,dp,temp,n,m,x);
           
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        
        int x = image[sr][sc];
        dfs(sr,sc,image,newColor,n,m,x);
        return image;
    }
};
