class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int res = 0 ;
        int lmax[n],rmax[n];
        
        //leftarray
        lmax[0]=arr[0];
        for (int i = 1 ; i<n;i++)
        {
            lmax[i]= max(lmax[i-1],arr[i]);
        }
        //rightarray
        rmax[n-1]=arr[n-1];
        for(int i =n-2 ; i>=0;i-- )
        {
            rmax[i]=max(rmax[i+1], arr[i]); 
        }
        
        for(int i =1;i<n-1;i++)
        {
            res =  res + min(rmax[i],lmax[i]) - arr[i];
        }
        return res;
    }
};
