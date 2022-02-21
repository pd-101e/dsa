class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        // O(n) T.C
        // SWAP SORT ALGO
        int i = 0 ;
        while(i < n){
            if(arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i] , arr[arr[i]-1]);
                
            }
            else{
                i++;
            }
        }
        int missing , dup;
        for(int i = 0 ; i<n ; i++)
        {
            if(arr[i] != i+1)
            {
                missing = i+1;
                dup = arr[i];
            }
        }
        int * ans = new int[2];
        ans[0] = dup;
        ans[1] = missing;
        return ans;
        
    }
};
