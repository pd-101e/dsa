class Solution
  {
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int n , int f)
    {
        if(f==0||f==1)
        return f;
        if(n==1)
        return f;
        if(dp[n][f] != -1)
        return dp[n][f];
        int ans = INT_MAX;
        for(int k = 1 ; k<=f ; k++)
        {
            int low , high;
            if(dp[n-1][k-1]!= -1)
             low =  dp[n-1][k-1];
            else{
                low = solve(n-1,k-1);
                dp[n-1][k-1] =low;
            }
             if(dp[n][f-k]!= -1)
             high =  dp[n][f-k];
            else{
                low = solve(n,f-k);
                dp[n][f-k] = low;
            }
            int temp = 1 + max(low,high);
            ans = min(temp,ans);
        }
        dp[n][f] =  ans ;
        return dp[n][f];
    }
    
    int eggDrop(int n, int f) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return solve(n,f);
    }
};
