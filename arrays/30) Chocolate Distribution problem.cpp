class Solution{
public:
    long long findMinDiff(vector<long long> arr, long long n, long long m){
    //code
    sort(arr.begin(),arr.end());
    
    long long diff = arr[m-1] - arr[0];
    
    for(int i = m ; i<n  ; i++)
    {
      diff = min(diff,arr[i] - arr[i-m+1] );  
    }
    return diff;
    
     
    
    }   
};
