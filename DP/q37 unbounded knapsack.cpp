class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[N+1][W+1];
        memset(dp,0,sizeof(dp));
        for(int i = 1 ; i<=N ; i++)
        {
            for(int j = 1 ; j<=W ; j++)
            {
                if(wt[i-1]<=j) // remember the j is weight now be careful
                {
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][W];
    }
};
