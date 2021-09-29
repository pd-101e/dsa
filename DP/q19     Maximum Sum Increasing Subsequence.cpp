
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int mis[n];
	    
	    for(int i = 0 ; i<n ; i++)
	    {
	        mis[i] = arr[i];
	        for(int j = 0 ; j<i ; j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                mis[i] = max(mis[i], arr[i]+mis[j]);
	            }
	        }
	    }
	    int res = mis[0];
	    for(int i = 0 ; i<n ; i++)
	    {
	      
	       res = max(res,mis[i]);
	    }
	    return res;
	}  
};
