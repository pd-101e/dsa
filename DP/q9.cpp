class Solution
  {
public:

   long long int  mod = 1000000007;
    int countFriendsPairings(int n) 
    { 
        // code here
        long long int dp[n+1];
          dp[0] = dp[1] = 1;
        
        for(int i = 2 ; i<=n ; i++)
         {
             dp[i] = (dp[i-1] + ( (i-1)*dp[i-2] ))%mod;
         }
         return dp[n];
        
    }
}; 
