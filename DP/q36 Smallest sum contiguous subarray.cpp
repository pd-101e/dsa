#include <bits/stdc++.h>
using namespace std;


int smallestSumSubarr(int arr[], int n)
{
    int res = arr[0];
    int minending = arr[0];
    for(int i = 0 ; i<n ; i++)
    {
        minending = min(arr[i],minending+arr[i]);
        res = min(minending,res);
        
    }
    
    
    return res;
}

int main()
{
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: "
         << smallestSumSubarr(arr, n);
    return 0;
}
