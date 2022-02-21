class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        vector<long long int>left(n);
        vector<long long int>right(n);
        
        left[0] = 1;
        for(int i = 1 ; i<n ; i++)
        {
            left[i] = left[i-1] * nums[i-1];
        }
        right[n-1] = 1;
        for(int i = n-2 ; i>=0 ; i--)
        {
            right[i] = right[i+1] * nums[i+1];
        }
        vector<long long int>ans(n);
        
        for(int i = 0 ; i<n ; i++)
        {
            ans[i] = left[i] * right[i];
        }
        return ans;
        
    }
};

//
// My approach : prefix sum
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    
    vector<long long int> pre(n);
    
    pre[0] = 1;
    for (int i=1; i<n; i++) {
        pre[i] = pre[i-1]*nums[i-1];
    }
    
    long long int suf = 1;
    for (int i=n-2; i>=0; i--) {
        suf *= nums[i+1];
        pre[i] = pre[i]*suf;
    }
    
    return pre;  
}

// Mathematical approaches :
// i) output[i] = antilog((log(a[0]) + log(a[1]) + .. + log(a[n-1])) - log(a[i]))
// ii) output[i] = (product * pow(a[i], -1))  
