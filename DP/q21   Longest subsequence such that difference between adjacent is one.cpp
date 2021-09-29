class Solution{
public:
    int longestSubsequence(int n, int arr[])
    {
        // code here
        int dp[n];
        dp[0] = 1;
        for(int i = 1 ; i<n ; i++)
        {
            dp[i] = 1;
            // int count =1;
            
            for( int j = 0; j<i ; j++)
            {
                if(abs(arr[i]-arr[j])==1)
                {
                   dp[i] = max(dp[i],dp[j]+1);      // remember the +1
                    // dp[i] = max(dp[i],dp[j]+count); // my wrong approach
                }
                
            }
            
        }
        int ans = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
