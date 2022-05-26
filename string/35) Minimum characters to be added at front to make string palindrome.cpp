//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/
class Solution {
public:
    
    int solve(string &s1 , string &s2)
    {
        int n = s1.length();
        int dp[n+1][n+1];
        
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(i==0 || j ==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j = 1 ; j<=n ; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
    
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        int m = solve(s,t);
        return n-m;
    }
};

// method 2 by lps accepted solution
int solve(string str )
{
    int n = str.length();
    int lps[n] ;
    lps[0] = 0;
    int i = 1;
    int j = 0 ;
    while(i< n)
    {
        if(str[i] == str[j])
        {
            lps[i] = j+1;
            i++;
            j++;
        }
        else if(j!=0)
        {
            j = lps[j-1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
    return lps[n-1];
}

    int minChar(string str){
        //Write your code here
        
        string str2 = str;
        reverse(str2.begin(),str2.end());
      string concat = str + string(1,'$') + str2;
      
      int n = str.length();
      int m = solve(concat);
      return n -m ;
        
        
        
    }

