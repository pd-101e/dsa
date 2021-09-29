class Solution{
public:
    int maximumPath(int n, vector<vector<int>> m)
    {
        // code here
        int dp[n][n];
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {return m[0][0] ;}
        int ans = 0;
        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = n-1 ; j>=0; j--)
            {
                if(i==n-1)
                {
                    dp[i][j] = m[i][j];
                    continue;
                }
                else
                if(j==n-1)
                {
                    dp[i][j] = m[i][j] + max(dp[i+1][j-1],dp[i+1][j]); 
                }
                else
                if(j==0)
                {
                    dp[i][j] = m[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
                }
                else{
                    dp[i][j] = m[i][j] + max({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
                }
                 ans = max(dp[i][j],ans);
            }
            
        }
          return ans;  
        
    }
};
