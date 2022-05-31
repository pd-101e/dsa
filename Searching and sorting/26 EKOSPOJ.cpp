#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isvalid(vector<ll>&arr , ll val ,  ll k )
{
    int n = arr.size();
    ll sum = 0 ;
    for(int i = 0 ; i<n ; i++)
    {
        if(arr[i] > val)
        {
            sum += arr[i] - val;
        }
    }
    
    if(sum >= k)
    {
        return true;
    }
    else return false;
}

int main()
{
    ll n , m ;
    cin>>n;
    cin>>m;
   
    vector<ll>arr;
    ll mxx = 0 ;
    while(n--)
    {
        ll a ;
        cin>>a;
        mxx = max(mxx,a);
        arr.push_back(a);
    }
    
    ll start = 0 ;
    ll end = mxx;
    ll ans = 0;
    while(start <= end )
    {
        ll mid = start + (end - start)/2;
        
        if(isvalid(arr,mid, m))
        {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        
    }
    
    cout<<ans ;
    return 0;
    
}
