class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int n = S.length();
	    int low = 0 , high = n-1;
	    while(low<high)
	    {
	        if(S[low] != S[high])
	        {
	            return 0;
	        }
	        low++;
	        high--;
	    }
	    return 1;
	}

};
//***********************************************************************************88
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    string s = S;
	    reverse(s.begin(),s.end());
	    
	    return s == S;
	    
	    
	}

};
