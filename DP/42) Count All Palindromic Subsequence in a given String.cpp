class Solution{ 
  public:
    /*You are required to complete below method */
    long long int dp[1001][1001];
    long long int mod = pow(10,9) + 7; 
    long long int solve(int i , int j , string &str)
    {
        if(i>j)
        return 0;
        if(i == j)
        return 1;
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(str[i] == str[j])
        {
            dp[i][j] =  (solve(i+1 , j , str)%mod + solve(i , j-1 , str)%mod + 1)%mod;
            // if (dp[i][j] < 0) dp[i][j] += mod;
        }
        else {
            dp[i][j] =  (solve(i+1 , j , str )%mod + solve(i , j-1 , str)%mod - solve(i+1 , j-1 , str)%mod + mod)%mod;
            // if (dp[i][j] < 0) dp[i][j] += mod;
            /*
             long long int sub(long long int x, long long int y) {
        return ((x % mod) - (y % mod) + mod) % mod;
            */
        }
        
        return dp[i][j];
        
    }
    
    
    long long int  countPS(string str)
    {
       //Your code here
       memset(dp,-1,sizeof(dp));
       return solve(0,str.size() - 1 , str);
       
    }
     
};
