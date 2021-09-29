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
