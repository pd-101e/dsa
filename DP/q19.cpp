// by recursion

#include <bits/stdc++.h>
using namespace std;

int solve(int n , int k , vector<int>&arr)
{
    if(n==0||k==0)
        return 0;
    if(arr[n-1]<=k)
    {
        return solve(n-1,k/arr[n-1],arr) + solve(n-1,k,arr) + 1;
        
    }
    else return solve(n-1,k,arr);
    
}

int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    return solve(n,k,arr);
}

// Driver code
int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << productSubSeqCount(A, k) << endl;
}

---------------------------------X---------------------------------------X-------------------------------------------------
// by memoisation
  
#include <bits/stdc++.h>
using namespace std;

int memo[101][101];
int solve(int n , int k , vector<int>&arr)
{
    if(n==0||k==0)
        return 0;
    if(memo[n][k]!=-1)
    {
        return memo[n][k];
    }
    if(arr[n-1]<=k)
    {
        memo[n][k] =  solve(n-1,k/arr[n-1],arr) + solve(n-1,k,arr) + 1;
        
    }
    else memo[n][k] = solve(n-1,k,arr);
    return memo[n][k];
    
}

int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    return solve(n,k,arr);
}

// Driver code
int main()
{
    
    memset(memo,-1,sizeof(memo));
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << productSubSeqCount(A, k) << endl;
}
---------------------------------X---------------------------------------X-------------------------------------------------
  // by dp tabulation
  
#include <bits/stdc++.h>
using namespace std;

int solve(int n , int k , vector<int>&arr)
{
    int dp[n+1][k+1];
    for(int i =0 ; i<=n ; i++)
    {
        for(int j = 0 ; j<=k ; j++)
        {
            dp[i][j] =0;
        }
    }
    
    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=k ; j++)
        {
            if(arr[i-1] <= j )
            {
                dp[i][j] = 1 + dp[i-1][j/arr[i-1]] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
    

    
}

int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    return solve(n,k,arr);
}

// Driver code
int main()
{
    
    
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << productSubSeqCount(A, k) << endl;
}


  
  


