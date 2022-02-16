
// A : given string to search
// B : vector of available strings

class Solution
{
public:
        int dp[1101];
    int solve(int index ,string &str , unordered_set<string>&s)
    {
        if(index >= str.length())
        return 1;
        
        if(dp[index]!= -1)
        return dp[index];
        int ans = 0;
        for(int i = index ; i<str.length() ; i++)
        {
            
            if(s.count(str.substr(index , i- index +1)) != 0)
            {
                ans = ans || solve(i+1,str,s) ;
            }
        }
        dp[index] = ans;
        return ans;
    }

    unordered_set<string>s;
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = B.size();
        for(int i = 0 ; i<n ; i++)
        {
            s.insert(B[i]);
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,A,s);
        
        
        
    }
};
