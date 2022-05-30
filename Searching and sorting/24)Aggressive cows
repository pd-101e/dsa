#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll d,ll arr[],int n,int c )
{
    int count = 1;
    ll prev = arr[0];
    for(int i = 1 ; i<n ; i++)
    {
        
        if(arr[i]-prev >= d)
        {
            prev = arr[i];
            count++;
        }
        if(count == c)
            return true;
    }
    return false;
}
int solve(ll arr[] , int n , int c,ll d)
{
	    ll low = 0 , high = d;
    ll ans = 0 ;
    while(low<=high)
    {
        ll mid = low + (high - low )/2;
        
        if(check(mid,arr,n,c))
        {	ans = mid;
            low = mid+1;
            
        }
        else high = mid-1;
        
        
    }
    return ans;
    
}

int main(){
    // write your code
    int t ;
    cin>>t;
    while(t--)
    {
        int n ,c;
        cin>>n;
        // cout<<n<<endl;
        cin>>c;
        // cout<<c<<endl;
        ll arr[n];
        for(int i = 0 ; i<n ; i++)
        {
            cin>>arr[i];
            
        }
        sort(arr,arr+n);
        // for(int i = 0 ; i<n ; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        ll d ;
        d= arr[n-1]-arr[0];
        // cout<<endl<<d<<endl;
        cout<<solve(arr,n,c,d)<<endl;
    }
    return 0;
}
