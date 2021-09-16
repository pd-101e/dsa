// quick look up 

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int random(int arr[] , int l , int r )
    {
        int n = r-l+1;
        int pivot = rand() % n;
        swap(arr[l+pivot],arr[r]);
        return partitionlomuto(arr,l,r);
    }
    
    int partitionlomuto(int arr[],int l,int r)
    {
        int i = l-1;
        int pivot = arr[r];
        for(int j = l ; j<=r-1 ; j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
        
    }
    
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        while(l<=r)
        {
        int p = random(arr, l,r);
        
        if(p==k-1)
        {
            return arr[k-1];
        }
        else if(p>k-1)
        {
            r=p-1;
        }
        else{
            l=p+1;
        }
            
            
        }
        return -1;
    }
};
