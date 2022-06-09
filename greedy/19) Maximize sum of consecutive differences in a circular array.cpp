long long int maxSum(int arr[], int n)
{
    long long int sum = 0 ;
    
    vector<int>v;
    sort(arr,arr+n);
    for(int i = 0 ; i<n/2 ; i++)
    {
        v.push_back(arr[i]);
        v.push_back(arr[n-1 - i]);
    }
    if(n & 1)
    {
        v.push_back(arr[n/2]);
    }
    
    for(int i = 0 ; i< n-1 ; i++)
    {
        sum += abs(v[i] - v[i+1]);
    }
    // cout<<sum<<endl;
    
    sum += abs(v[0] - v[n-1]);
    // cout<<sum<<endl;
    return sum;
    
}
