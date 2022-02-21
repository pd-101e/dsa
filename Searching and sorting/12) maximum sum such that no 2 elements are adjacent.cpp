// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[], int n )
{
    int dp[n+1];
    if(n>=0)
    dp[0] = 0;
    if(n>=1)
    {
        dp[1] = arr[0];
    }
    if(n>=2)
    {
        dp[2] = max(arr[0],arr[1]);
    }
    for(int i = 3 ; i<=n ; i++)
    {
        dp[i] = max(dp[i-2]+arr[i-1],dp[i-1]);
    }
    return dp[n];
    
   
}
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        return solve(arr,n);
        
    }
};
