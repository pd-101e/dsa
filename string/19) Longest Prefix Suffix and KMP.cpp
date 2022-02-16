// LPS
//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    int i = 1;
	    int j = 0;
	   // int res = 0;
	    vector<int> lps(s.size(), 0);
	    while(i<n)
	    {
	        if(s[i] == s[j])
	        {
	            lps[i] = j+1;
	           // res = max(res,lps[i]);
	            j++;
	            i++;
	        }
	        else {
	            if(j!=0)
	            {
	                j = lps[j-1];
	            }
	            else {
	                lps[i] = 0;
	                i++;
	            }
	        }
	    }
	    
	   // return res; my wrong approoach
	   return lps[n-1]; // as we want longes prefix which is also a pre3fix
	}
};


// KMP https://practice.geeksforgeeks.org/problems/pattern-search-kmp/1/?track=DSASP-Strings&batchId=154

//Function to fill lps[] for given patttern pat[0..M-1].
void computeLPSArray(string pat, int M, int* lps) 
{ 
	// Your code here
	// first i have to preprocess the lps array
	int n = M;
	int i = 1 , j=0;
	while(i<n)
	{
	    if(pat[i] == pat[j])
	    {
	        lps[i] = j+1;
	        i++;
	        j++;
	    }
	    else{
	        if(j==0)
	        {
	            i++;
	        }
	        else{
	            j = lps[j-1];
	            // be carefull 
	        }
	    }
	}
	
	
	
} 

//Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) 
{
    // Your code here
    int n = pat.size();
    int *lps = new int[n];
    for(int i = 0; i<n ; i++)
    {
        lps[i] = 0;
    }
    computeLPSArray(pat,n,lps);
    
    int m = txt.size();
    int i = 0 , j = 0 ;
    while(i<m and j<n)
    {
        if(pat[j] == txt[i])
        {
            
            i++;
            j++;
        }
        else {
            if(j==0)
            {
                i++;
            }
            else {
                j = lps[j-1];
                
            }
        }
    }
    if(j == n)
    return true;
   return false;
    
    
}


