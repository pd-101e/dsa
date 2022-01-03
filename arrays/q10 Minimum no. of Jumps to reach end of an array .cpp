// O(N^2) DP soln 
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if (n <= 1) 
            return 0; 
      
        // Return -1 if not possible to jump 
        if (arr[0] == 0) 
            return -1; 
        int dp[n];
         dp[0] = 0;
        for(int i = 1 ; i<n ; i++)
        {
            dp[i] = INT_MAX;
        }
        for(int i = 1 ; i<n ; i++  )
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(arr[j] + j >= i)
                {
                    if(dp[j]!=INT_MAX)
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        if(dp[n-1]!=INT_MAX)
        return dp[n-1];
        else return -1;
    }
};


// O(N) iterative approach

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int maxr = arr[0];
        int step = arr[0];
        int jump = 1;
        
        if(n==1)
        {
            return 0;
        }
        else if(arr[0]==0)
        {
            return -1;
        }
        
        for(int i = 1 ; i<n ; i++)
        {
            if(i==n-1)
            {
                return jump;
            }
            maxr = max(maxr, i + arr[i]);
            step--;
            if(step == 0)
            {
            if(i>=maxr)
            {
                return -1;
            }
            
            jump++;
            step = maxr - i;
            
            }
            
            
        }
    }
};

