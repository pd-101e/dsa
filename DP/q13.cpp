class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int len[] = {x,y,z};
        dp[0] = 0;
        for(int i = 1 ; i<=n ;i++ )
        {
            for(int j = 0 ; j<3 ; j++)
            {
                if(i>=len[j] && dp[i - len[j]]!=-1) // remember the condition its imp
                {
                    dp[i] = max(dp[i],1 + dp[i - len[j]]);
                }
            }
        }
        if(dp[n]==-1)
        return 0;
        else return dp[n];
        
    }
};
