/*
 search space time lenge
 lower bound , upper bound , minimize the time
 agr lower aur upper bound samjh nhi aya kabhi to
 lb = 0 and ub = INT_MAX
 
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool isvalid(vector<int>&arr , ll timeub , int n , int reqparatha)
{
    int paratha = 0 ;
    ll time = 0 ;
    for(int i = 0; i<n ; i++)
    {
        time = arr[i];
        int j = 2;
        while(time <= timeub)
        {
            paratha++;
            time = time + arr[i]*j; // rank R , 2R , 3R , 4R
            j++;
        }
        if(paratha >= reqparatha)
            return true;
        
    }
    return false;
}

int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int p ;
        cin>>p;
        int n ;
        cin>>n;
        vector<int>arr;
        while(n--)
        {
            int a ;
            cin>>a;
            arr.push_back(a);
        }
        
        ll start = 0;
        ll end = ((p*(p+1))/2)*arr[n-1];
        ll ans = 0;
        sort(arr.begin(),arr.end());
        while(start <= end)
        {
            ll mid = start + (end - start)/2;
            
            if(isvalid(arr,mid,n,p))
            {
                ans = mid ;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            
        }
        cout<<ans<<endl;
        
    }
    
    
    return 0;
}
