// Approach 1: Simple Linear Search

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Complete the function
    for(int i = 0 ; i<n ; i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }
    return -1;
    
}    	

// Approach 2: Instead of searching linearly we can jump through unnecessary comparisions. Jump by abs(x- array[i]) /k if the
// current element is not x.

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Complete the function
    int i = 0 ;
    int ans = -1;
    while(i<n)
    {
        if(arr[i] == x)
        {
            ans = i;
            break;
        }
        i = i + max(1 , abs(arr[i] -x )/k); // we jump this many times and check for the requeired ele
    }
    return ans;
    
}    	
