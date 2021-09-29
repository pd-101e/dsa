/// simple one 


{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int inc = arr[0];
        int exc = 0;
        
        for(int i = 1 ; i<n ; i++ )
        {
            int newinc = arr[i] + exc;
           int  newexc = max(inc,exc);
            
            inc = newinc;
            exc = newexc;
            
        }
        int ans = max(inc,exc);
        return ans;
        
    }
};



//dp method
class solution{

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


/// recursive method
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n )
{
    if(n<=0)
    {
        return 0;
    }
    
    return max(arr[n-1]+solve(arr,n-2),solve(arr,n-1));
}






int main()
{
    int arr[] = {1,2,3};
    int n = 3 ;
    cout<<endl<<solve(arr,n)<<endl;
}
