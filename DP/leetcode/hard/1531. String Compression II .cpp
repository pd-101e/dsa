/*
Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
Example 2:

Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.
Example 3:

Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
Constraints:

1 <= s.length <= 100
0 <= k <= s.length
s contains only lowercase English letters.
*/
// approach one 
// by memo / top down 
class Solution {
public:

    int countlen(int count)
    {
        // suppose a is coming 9 times , so we write a9 - length(a9) = 2
        // count>=10 - suppose 15 times , so length(a15) string = 3
          if(count==1)return 1; 
        else{
            if(count<10)return 2; 
            else{
                if(count<100)return 3; 
                else return 4;  
            }
        }

    }


    int minlen(int i , int k , int n , string &s, vector<vector<int>>&dp)
    {
       if(i >= n-k)
       {
           return 0;
       }
       if(k<0)
       {
           return 101;
       }
       if(dp[i][k] != 101) return dp[i][k];

        int res = minlen(i+1, k-1 , n , s , dp);// delete the current character making possible del i.e k = k-1  character find out min len for the i + 1 string
        int same = 0 , del = 0 , length = 0;
        // For all continuous s[i] characters (can delete k characters)
        for(int j = i ; j<n and k - del >= 0 ; j++ )
        {
            if(s[i] == s[j])
            {
                same++;// to get the proper count for the num of same elements
            }
            else { del++ ;}// not same char will get deleted 
            // like word break problem by 
            // maintaining the window from current to end and giving recursive call to rest of us 
            res = min(res , countlen(same) + minlen(j+1 , k -del , n , s , dp));
            
        }
        return dp[i][k] = res; 

    }

    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(k+1,101));
        int ans = minlen(0,k,n,s,dp);
        return ans;
    }
};

/*******************************************************************8
Approach two bottom up/ tabulation
*/
/*
Memo to tabulation 

idea to write tabulation 
idea 1....
after coparing from the memo code or recursive code ...
we get idea for tabulation to include i + 1 in tabulation we start i from n -> 0; this result to add dp[i+1][]

we get idea for tabulation to include j - 1 in tabulation we start k form 0 -> k; this result to write code in tabulation as dp[i+1][j-1]
for better understaning compare tabulation(bottom up) with memo(top - down);

code plan 

memo 
i = 0 to n;
k = k to 0;

as tabulation is bottom up approach we 

start i from n -> 0;
k form 0 -> k;

answer will be stored in dp[0][k] means dp[0] = number of n characters 
dp[k] =  for n deletion ,
*/

class Solution {
public:

        int countlen(int count)
        {
             // suppose a is coming 9 times , so we write a9 - length(a9) = 2
        // count>=10 - suppose 15 times , so length(a15) string = 3
            if(count == 1)
            {
                return 1;
            }
            else if(count <10)
            {
                return 2;
            }
            else if(count < 100)
            {
                return 3;
            }
            else 
            return 4;
        }

    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(k+1,INT_MAX - n));
        for(int i = n ; i >= 0 ; i--)
        {
            for(int j = 0 ; j<=k ; j++)
            {
                if(i == n ) // base condition 
                {dp[i][j] = 0; // dp[n][j] = 0 ; because as we are starting i from n to 0 base case should be added at i ==n as string is break in subProblem from last and i == n means 0 characters in string for any deletion alway give min length 0
                continue;
                }
                if(j>0) // check added so that j-1 not get in negative
                dp[i][j] = dp[i+1][j-1];
                
                int same = 0 , del = 0 , length = 0 ;
                for(int end = i ; end<n; end++)
                {
                    // as we are ignoring the i == n time loop so se have just done s[i] no s[i-1]
                    if(s[i] == s[end])
                    {
                        same++;
                    }
                    else del++;
                    if(j-del>=0) // to check j-del never be negative
                    dp[i][j] =  min(dp[i][j], countlen(same) + dp[end + 1][j - del] );
                }


            }
        }
        return dp[0][k];
    }
};

/*
https://leetcode.com/problems/string-compression-ii/solutions/4468931/leetcode-daily-problem-very-easily-explained-optimized-c-java/?envType=daily-question&envId=2023-12-28

https://leetcode.com/problems/string-compression-ii/solutions/4469055/2-dimensional-dp-c-java-python-javascript-golang/?envType=daily-question&envId=2023-12-28
*/




