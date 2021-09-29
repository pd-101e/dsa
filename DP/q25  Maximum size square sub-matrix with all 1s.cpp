class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int dp[n][m];
        if(n==1)
        {
            for(int i = 0 ; i<m ; i++)
            {
                if(mat[0][i] == 1)
                {return 1;}
               
            }
            
            
        }
        if(m==1)
        {
            for(int i = 0 ; i<n ; i++)
            {
                if(mat[i][0] == 1)
                {return 1;}
                
            }
        }
        int ans = 0;
        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = m-1 ; j>=0 ; j--)
            {
                if(i==n-1 and j == m-1)
                {
                   dp[i][j] = mat[i][j]; 
                }
                else if(i==n-1)
                {
                    dp[i][j] = mat[i][j]; 
                }
                else if(j==m-1)
                {
                    dp[i][j] = mat[i][j]; 
                }
                else if(mat[i][j]==0)
                {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 1 + min({dp[i+1][j+1],dp[i][j+1],dp[i+1][j]});
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
