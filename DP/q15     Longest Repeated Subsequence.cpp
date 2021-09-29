public:
	
	int lcs(int n,int m, string s1, string s2)
	{
	    int dp[n+1][m+1];
	    for(int i = 0 ; i<=n ; i++)
	    {
	        for(int j = 0 ; j<=m ; j++)
	        {
	            if(i==0||j==0)
	            {
	                dp[i][j] = 0 ;
	            }
	        }
	    }
	    for(int i = 1 ; i<=n ; i++)
	    {
	        for(int j = 1 ; j<=m ; j++)
	        {
	            if(s1[i-1]==s2[j-1] && i!=j)
	            {
	                dp[i][j] = 1 +dp[i-1][j-1];
	            }
	            else 
	            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
	        }
	    }
	    return dp[n][m];
	}
	
	
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string s2 = str;
		    int n = str.length();
		    return lcs(n,n,str,s2);
		}

};
