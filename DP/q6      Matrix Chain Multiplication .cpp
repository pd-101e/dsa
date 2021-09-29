class Solution{
public:

    int  memo[101][101];
    int solve(int arr[], int i , int j )
    {
        if(i>=j)
        {
            return 0;
        }
       
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
         int mn = INT_MAX;
        for(int k = i ; k<=j-1 ; k++)
        {
            int tempans = solve(arr,i,k) + solve(arr,k+1, j) + (arr[i-1]*arr[k]*arr[j]);
            mn = min(tempans,mn);
        }
        memo[i][j] = mn;
        return memo[i][j];
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        memset(memo,-1, sizeof(memo));
        return solve(arr,1,n-1);
    }
};
