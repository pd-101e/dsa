// in solution 1
// in this we have mltiply i as long long int so a[i]*i get automatically type casted to the long long int no manual type casting req
class Solution{
  public:
   long long int mod = pow(10,9) + 7;
    
    int Maximize(int a[],int n)
    {
        // Complete the function
        sort(a , a+n);
        
        long long int sum = 0 ;
        
        for(long long int i = 0 ; i<n ; i++)
        {
            sum = sum + (a[i]*i)%mod ;
            
            sum = sum%mod;
        }
        
        return sum;
        
    }
};

// in solution 2 
// we have doen manual type casting
class Solution{
  public:
   long long int mod = pow(10,9) + 7;
    
    int Maximize(int a[],int n)
    {
        // Complete the function
        sort(a , a+n);
        
        unsigned long long int sum = 0 ;
        
        for( int i = 0 ; i<n ; i++)
        {
            sum = sum + ((unsigned long long int)a[i]*i)%mod ; // type casting 
            
            sum = sum%mod;
        }
        
        return sum;
        
    }
};
