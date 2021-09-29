// greedy approach

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int K)
    {
        // Your code goes here   
        int sum = 0;
        sort(arr,arr+n,greater<int>());
        for(int i = 0 ; i<n-1 ; i++)
        {
            if(abs(arr[i]-arr[i+1]) < K )
            {
                sum = sum + arr[i] + arr[i+1];
                i++;
            }
        }
        return sum;
    }
};


// recursive
class Solution{
    public:
    
  
    
    int solve(int arr[] , int n , int k)
    {
        if(n<=0)
        return 0;
        if(n==1)
        return 0;
        
        if(arr[n-1] - arr[n-2] <k)
        return arr[n-1] + arr[n-2] + solve(arr,n-2,k);
        else
        return solve(arr,n-1,k);
        
    }
    
    
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int K)
    {
        // Your code goes here   
        sort(arr,arr+n);
        return solve(arr,n,K);
        
    }
};


// dp method
int solve(int arr[] , int n , int k)
    {
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        for(int i = 2 ; i<=n ; i++)
        {
            if(arr[i-1]-arr[i-2]<k)
            dp[i] = arr[i-1] + arr[i-2] + dp[i-2];
            else
            dp[i] = dp[i-1];
        }
        return dp[n];
        
    }
    
    
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int K)
    {
        // Your code goes here   
        sort(arr,arr+n);
        return solve(arr,n,K);
        
    }
};

