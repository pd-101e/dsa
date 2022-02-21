
class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code herell count = 0 ;
        ll presum = 0 ;
        unordered_map<ll,ll>m;
        int count = 0;
        for(int i = 0 ; i<n ; i++)
        {
            presum = presum + arr[i];
            if(presum==0)
            {
                count++;
            }
            // we check if that presum exist or not if ye inc the count by number of presum count
            if(m.count(presum)!=0)
            {
                count+=m[presum];
            }
            m[presum]++; // we are maintaining the count of every presum
        }
        return count;
    }
};
