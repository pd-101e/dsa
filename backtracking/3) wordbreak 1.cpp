

int solve(int index , string &A , unordered_set<string>&s, int *dp)
{
            if(index == A.length() )
            {
                return 1;
            }

            if (dp[index]!=-1)
            return dp[index];
            int result = 0 ;
            int c = A.length();
            int p = min(index+20,c);
            /*

    Earlier I was also getting TLE.
Note that the length of the word in the dictionary is constrained to <=20. 
So, one need not extract words of all length from the original string s.
 Only extract words till the length(word)<=20. This removed the TLE from my code.

            */
    for(int k = index ; k<p ; k++)
    {
            if(s.count(A.substr(index,k - index + 1)) ==1 )
            {
                
                result = result || solve(k+1,A,s,dp);;
            }
            
    }

    dp[index] = result;
    return result;
}



int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string>s;
    int n = B.size();
    for(int i = 0 ; i<n ; i++)
    {
        s.insert(B[i]);
    }
    int *dp = new int[6501];
    for(int i =0 ; i < 6501 ; i++)
    {
        dp[i] = -1;
    }
    return solve(0,A,s,dp);


}

