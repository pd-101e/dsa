public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        //Your Code Here
         sort(arr,arr+n);
    
    for(int i = 0 ; i<n ; i++)
    {
        int j = i+1;
        int k = n-1;
        while(j < k)
        {
            if(arr[i] + arr[j] + arr[k] == X)
            {
                return true;
            }
            else if(arr[i] + arr[j] + arr[k] >X)
            {
                k--;
            }
            else{
                j++;
            }
        }
        
    }
    return false;
    }

};
