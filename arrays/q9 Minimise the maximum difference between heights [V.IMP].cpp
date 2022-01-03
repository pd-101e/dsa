
//Minimize the Heights II
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int diff = arr[n-1]- arr[0];
        
        int maxi = arr[n-1];
        int mini = arr[0];
        
        for(int i=1; i<n; i++)
        {
            if(arr[i]-k<0)
            continue;
            
            mini = min(arr[0]+k, arr[i]-k);
            maxi = max(arr[n-1]-k, arr[i-1]+k);
            diff = min(diff, maxi-mini);
        }
        return diff;

    }
};

//Minimize the Heights I
//https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1/#
class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int diff = arr[n-1]- arr[0];
        
        int maxi = arr[n-1];
        int mini = arr[0];
        
        for(int i=1; i<n; i++)
        {
            
            
            mini = min(arr[0]+k, arr[i]-k);
            maxi = max(arr[n-1]-k, arr[i-1]+k);
            diff = min(diff, maxi-mini);
        }
        return diff;
    }
};

// test case failed dont't know why
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll getmindiff(ll arr[], int n , ll k)
{
    if(n==1)
    {
        return 0;
    }
    sort(arr,arr+n);
        ll small = arr[0] + k;
        ll big = arr[n-1] - k;
        if(small > big )
        {
            swap(small , big);
        }
        ll ans = arr[n-1] - arr[0];
        for(int i = 1 ; i<n-1 ; i++)
        {
            ll sub = arr[i] - k;
            ll add = arr[i] + k;
            if(sub>=small or add <= big)
                continue;
            else if(big - sub <= add-small)
            {
                small = sub;
            }
            else {
                big = add;
            }
        }
        
        ans = min(ans,big - small);
        return ans ;
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        ll k;
        
        cin>>k;
        ll arr[n];
        for(int i = 0 ; i<n ; i++)
        {
            cin>>arr[i];
        }
        cout<<getmindiff(arr,n,k)<<endl;
        
        
    }
    return 0;
}
