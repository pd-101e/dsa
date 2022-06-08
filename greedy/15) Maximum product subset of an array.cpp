#define ll long long int
class Solution{
    public:
    
    ll mod = pow(10,9) + 7;
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here 
        
        int zerocount = 0;
        ll prod = 1;
        int negativecount = 0;
        int maxneg = INT_MIN;
        
        for(int i = 0 ; i<n ; i++)
        {
            if(a[i] == 0)
            {
                zerocount++;
                continue;
            }
            
            if(a[i] < 0 )
            {
                negativecount++;
                maxneg = max(a[i],maxneg);
            }
            
            
            prod *= a[i];
            prod = prod%mod;
            
        }
        
        if(zerocount == n)
        {
            return 0;
        }
        else if(negativecount == 1 and zerocount != 0 and zerocount + negativecount == n )
        {
           return 0;
        }
        else if(negativecount & 1 and n!=1)
        {
            prod = prod/maxneg;
        }
        
        return prod%mod;
    }
};
