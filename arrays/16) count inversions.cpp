class Solution{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    #define ll long long int

ll merge(ll arr[],ll low , ll mid , ll high)
{
    ll n = mid - low +1;
    ll m = high - mid;
    vector<ll>left(n);
    vector<ll>right(m);
    for(int i = 0 ; i< n ; i++)
    {
        left[i] = arr[low+i];
    }
    for(int i = 0 ; i<m ; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    
    ll i = 0 , j = 0 , res = 0 , k = low ;
    
    while(i<n and j<m )
    {
        if(left[i]<=right[j])
        {
            arr[k] = left[i];
            i++;k++;
        }
        else {
            arr[k] = right[j];
            res = res +( n - i);
            j++;k++;
        }
    }
    
    while(i<n)
    {
        arr[k] = left[i];
        i++;k++;
    }
    while(j<m)
    {
        arr[k] = right[j];
        j++;k++;
    }
    return res;
    
}

ll mergesort(ll arr[],ll low , ll high)
{
    ll res = 0 ;
    
    if(low<high)
    {
        ll mid = low + (high -low )/2;
        res += mergesort(arr,low , mid);
        res += mergesort(arr,mid+1,high);
        res += merge(arr,low,mid,high);
    }
    return res;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    ll low  = 0 ; ll high = N-1;
    return mergesort(arr,low,high);
}


};
