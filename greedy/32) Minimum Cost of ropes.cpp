class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long ,vector<long long>,greater<long long>>pq(arr,arr+n);
        long long res=0;
        while(pq.size()>1)
        {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            
            res += first+second;
            pq.push(first+second); // remeber to push first +second  in pq;
            
            
        }
        return res;
        
    }
};
