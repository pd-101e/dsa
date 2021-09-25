class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int search(int arr[] , int n , int low , int high ,int key)
    {
        while(low<high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] >= key )
            {
                high = mid;
            }
            else low = mid+1;
        }
        return high;
    }
    
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       int tail[n];
       int len = 1;
       tail[0] =arr[0];
       for(int i = 1 ; i<n ; i++)
       {
           if(tail[len-1]<arr[i])
           {
               tail[len] = arr[i];
               len++;
           }
           else
           {
               int c = search(tail,len,0,len-1,arr[i]);
               tail[c] =arr[i];
           }
       }
       
       
       return len;
    }
};
