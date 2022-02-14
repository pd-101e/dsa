//approach 1 //dp
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long pos = arr[0];
	    long long neg = arr[0];
	    long long res = arr[0];
	    
	    for(int i = 1 ; i<n ; i++)
	    {
	        if(arr[i] < 0)
	        {
	            swap(pos,neg);
	        }
	        
	        pos = max(long(arr[i]),long (pos*arr[i]));
	        neg = min(long(arr[i]), long (neg * arr[i]));
	        res = max(res,pos);
	        
	        
	    }
	    
	    return res;
	}
};

// approach iterative 
long long maxProduct(vector<int> arr, int n) {
	    // code here
	    
	    ll max_ending = 1;
	    ll min_ending = 1;
	    ll res = LONG_MIN;
	    if(n==1)
	    {
	        res = arr[0];
	        return res;
	    }
	    for(int i = 0 ; i<n ; i++)
	    {
	        if(arr[i]>0)
	        {
	            max_ending = arr[i] * max_ending ;
	            min_ending = min(1LL,arr[i]*min_ending);
	            
	        }
	        else if(arr[i]<0)
	        {
	            ll temp = max_ending;
	            max_ending = max(1LL,min_ending * arr[i]);
	            min_ending = temp * arr[i];
	        }
	        else if(arr[i]==0)
	        {
	            max_ending = 1;
	            min_ending = 1;
	            
	        }
	        res = max(res,max_ending);
	    }
	   return res; 
	}
};
