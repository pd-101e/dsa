class Solution
{
 public:
    long long mod = 1000000007;
    long long countWays(int n, int k){
        // code here
        if(n==1)
        {
            return k;
        }
        long long same = k;
        long long diff = k*(k-1);
        long long total = same + diff ;
        for(int i = 3 ; i<=n ; i++)
        {
            same = diff;
            diff = total*(k-1);
            total = (same + diff)%mod;
        }
        return total;
    }
};
