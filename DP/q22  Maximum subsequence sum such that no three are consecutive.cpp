// by recursion

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return arr[0];
    }
    if(n==2)
    {
        return arr[0]+arr[1];
    }
    if(n==3)
    {
        return max({arr[0]+arr[1],arr[0]+arr[2],arr[1]+arr[2]});
    }
    
    return max({ solve(arr,n-1), arr[n-1] +  solve(arr,n-2),arr[n-1]+arr[n-2]+ solve(arr,n-3)});
}






int main()
{
    int arr[] = { 100, 1000, 100, 1000, 1}; //2101
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, n)<<endl;
    return 0;
}



// by tabulation method
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    int dp[n+1];
    if(n>=0)
    {
        dp[0] = 0;
    }
    if(n>=1)
    {
        dp[1] = arr[0];
    }
    if(n>=2)
    {
        dp[2] = arr[0] + arr[1];
    }
    if(n>3)
    {
        dp[3] = max({dp[0]+dp[1],dp[1]+dp[2],dp[0]+dp[2]});
    }
    
    for(int i = 4 ; i<=n ; i++)
    {
        dp[i] = max({dp[i-1],dp[i-2]+arr[i-1],dp[i-3]+arr[i-1]+arr[i-2]});
    }
    return dp[n];
}

int main()
{
    int arr[] = { 100, 1000, 100, 1000, 1}; //2101
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, n)<<endl;
    return 0;
}

