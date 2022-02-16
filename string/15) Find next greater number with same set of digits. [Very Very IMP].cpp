class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
       
        int idx = -1;
        for(int i = N-1 ; i>=1 ; i--)
        {
            if(arr[i-1] < arr[i] )
            {
                idx = i;
                break;
            }
        }
        if(idx == -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        int prv = idx;
        for(int i = idx+1 ; i<N ; i++)
        {
            if(arr[idx - 1] < arr[i] and arr[prv] > arr[i])
            {
                prv = i;
            }
            
        }
        swap(arr[idx - 1],arr[prv]);
        reverse(arr.begin() + idx ,arr.end());
        return arr;
        
        
    }
};
