class Solution{
public:

    bool subsetsum(int arr[], int n , int sum)
    {
        bool dp[n+1][sum+1];
        for(int i = 0 ; i<=n ; i++)
        {
            for(int j = 0; j<=sum ; j++)
            {
                if(i==0)
                {
                    dp[i][j] = false;
                    continue;
                }
                if(j==0)
                {
                    dp[i][j] = true;
                    continue;
                }
            }
        }
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j =1 ; j<=sum ; j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j - arr[i-1]]||dp[i-1][j];
                }
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
        
    }


    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0 ; i<n ; i++)
        {
            sum += arr[i];
        }
        if(sum%2!=0)
        return 0;
        else
        {
            int checksum = sum/2;
            if (subsetsum(arr,n,checksum))
            {
                return 1;
            }
            else return 0;
            
        }
    }
};
