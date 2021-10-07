    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxsubarray = 0;
        long long res = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            maxsubarray += arr[i];
            res = max(res,maxsubarray);
            if(maxsubarray<=0)
            {
                maxsubarray = 0;
            }
            
        }
        return res;
    }
};
