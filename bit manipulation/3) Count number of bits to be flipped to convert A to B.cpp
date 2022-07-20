class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    
    int countsetbits(int n)
    {
        int count = 0 ;
        while(n>0)
        {
            count++;
            n = n & (n-1);
        }
        return count;
    }
    
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int c = a ^ b;
        int ans = countsetbits(c);
        return ans;
        
    }
};
