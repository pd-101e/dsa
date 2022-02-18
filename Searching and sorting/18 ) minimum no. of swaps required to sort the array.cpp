class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    // approach 
    /*
    vector of pair banaya aur fir usse sort karidye  pair(number , index)
    fir uss sorted order ko original me convert kardiya 
    */
    
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pair<int,int>>arr(n);
	    for(int i = 0 ; i<n ; i++)
	    {
	        arr[i].first = nums[i];
	        arr[i].second = i;
	    }
	    sort(arr.begin() , arr.end());
	    // lets iterate over the arr now 
	    int minswaps = 0;
	   // for(int i = 0 ; i<n ; i++)
	    for(int i = 0 ; i<n ; )
	    {
	        if(arr[i].second == i)
	        {
	           // continue;
	           i++;
	        }
	        else {
	            swap(arr[i] , arr[arr[i].second]);
	            minswaps++;
	           // i--;
	        }
	    }
	        
	    return minswaps;
	    
	    
	}
};
