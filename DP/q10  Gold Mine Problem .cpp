class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> arr)
    {
        // code here
         int dp[n][m];
       
        for(int j = m-1 ; j>=0 ; j--)
        {
            for(int i = 0 ; i<n ; i++)
            {
                if(j==m-1)
                {
                    dp[i][j] = arr[i][j];
                }
                else if(i==0 && n==1)
                // handle the base case when one row is there 
                {
                    dp[i][j] =arr[i][j] + dp[i][j+1];
                }
                else if(i==0 && n>1)
                {
                    dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i+1][j+1]);
                }
                else if(i==n-1)
                {
                    dp[i][j] = arr[i][j] + max(dp[i-1][j+1],dp[i][j+1]);
                }
                else dp[i][j] = arr[i][j] + max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]));
            }
        }
        
        int mx = dp[0][0] ;
        for(int i = 1 ; i<n ; i++)
        {
            if(dp[i][0] > mx)
            mx =dp[i][0];
        }
        return mx;
    }
};
