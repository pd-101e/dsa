class Solution{
public:
    string smallestNumber(int s, int d){
        // code here 
        
        
        int digits[d] ;
        digits[0] = 1;
        s = s - 1;
        int mysum = 0;
        int j = 9;
        for(int i = d-1 ; i>=1 ; )
        {
            if(mysum + j <= s)
            {
                digits[i] = j;
                i--;
               mysum = mysum + j;
            }
            else {
                j--;
            }
        }
        
        int rem = s - mysum + 1;
        if(rem >9)
        return "-1";
        digits[0] = rem;
        
        string ans = "";
        
        for(int i = 0 ; i<d ; i++)
        {
            ans += to_string(digits[i]);
        }
        return ans;
        
        
    }
};
