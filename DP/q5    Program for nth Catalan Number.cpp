class Solution
{
    public:
    //Function to find the nth catalan number.
    vector<cpp_int> memo; // we can create vector of type cpp int
    cpp_int count(int n )
    {
        if(n<=0)
        return 1;
        
        cpp_int res = 0;
        if(memo[n] != -1)
        {
            return memo[n];
        }
        for(int i = 0 ; i<n ; i++)
        {
            res += (count(i) * count(n-i-1));
           
        }
        memo[n] =  res;
        return memo[n];
    }
    
    cpp_int findCatalan(int n) 
    {
        //code here
       memo = vector<cpp_int> (n+1, -1); // initialised the vector int the function
        return count(n);
        
    }
};
