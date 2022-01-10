class Solution{
public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int>s;
        int presum = 0 ;
        
        for(int i = 0 ; i<n ; i++)
        {
            presum = presum + arr[i];
            if(presum == 0)
            { // base case handle
                return true;
            }
            if(s.count(presum) == 1)
            return true;
            
            s.insert(presum);
            
        }
        return false;
    }
};
