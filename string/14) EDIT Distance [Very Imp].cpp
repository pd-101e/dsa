#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    int mindist(string s1 , string s2 , int n , int m )
    {
        int dp[n+1][m+1];
        for(int i = 0 ; i<= n ; i++)
        {
            for(int j = 0 ; j<=m ; j++)
            {
                if(i==0)
                {
                    dp[i][j] = j;
                }
                if(j==0)
                {
                    dp[i][j] = i;
                }
                if(i==0 && j== 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ;j<=m ; j++ )
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else 
                dp[i][j] = 1 + min({dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1]});
            }
        }
        return dp[n][m];
    }
    
  
    int editDistance(string s1, string s2) {
        // Code here
        int n = s1.length();
        int m = s2.length();
        return mindist(s1,s2,n,m);
    }
};
