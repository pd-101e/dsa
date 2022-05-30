class Solution 
{
    public:
    //Function to find minimum number of pages.''
    
    bool isvalid(int arr[] , int n , int k , int mxx)
    {
        int students = 1;
        int sum = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            sum = sum + arr[i];
            if(sum > mxx)
            {
                students++;
                sum = arr[i];
            }
        }
        
        if(students > k )
        return false;
        
        return true;
        
    }
    int findPages(int arr[], int n, int k) 
    {
        //code here
        int start = arr[0];
        int end = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            start = max(arr[i],start);
            end += arr[i];
        }
        
        int ans = -1 ;
        
        while(start <= end)
        {
            int mid = start +( end - start)/2;
            
            if(isvalid(arr , n , k, mid))
            {
                ans = mid ;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            
        }
        
        
        return ans ;
    }
};
