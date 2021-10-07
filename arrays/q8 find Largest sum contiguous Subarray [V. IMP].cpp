class Solution{
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


// by dp

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int max_ending = arr[0];
        int res= arr[0];
        for(int i = 1; i<n;i++)
        {
            max_ending= max(max_ending +arr[i],arr[i]);
            res = max(res, max_ending);
        }
        return res;
    }
};
