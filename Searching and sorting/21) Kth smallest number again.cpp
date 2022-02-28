#include<bits/stdc++.h>
using namespace std;
 
 
 
// int solve(vector<pair<int,int>>&arr , int k, int idx)
// {
	
// 	int ans = -1;
// 	for(int i = 0 ; i<=idx; i++)
// 	{
// 		int diff = arr[i].second - arr[i].first + 1;
// 		if(k > diff )
// 		{
// 			k = k - diff ;
// 		}
// 		else {
// 			 ans = arr[i].first + k - 1;
// 			break;
// 		}
// 	}
// 	return ans;
// }
#define ll long long 
 
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n , q;
		cin>>n>>q;
		vector<pair<ll,ll>>arr;
		while(n--)
		{
			ll a , b;
		cin>>a>>b;
		arr.push_back({a,b});
		}
		sort(arr.begin(),arr.end());
		
		int idx = 0 ;
		for(int i = 1 ; i<arr.size() ; i++)
		{
			if(arr[i].first <= arr[idx].second)
			{
			arr[idx].second = max(arr[idx].second , arr[i].second);
			}
			else {
				idx++;
				arr[idx] = arr[i];
			}
		}
	
		while(q--)
		{
			ll k ;
			cin>>k;
			ll ans = -1;
	for(int i = 0 ; i<=idx; i++)
	{
		ll diff = arr[i].second - arr[i].first + 1;
		if(k > diff )
		{
			k = k - diff ;
		}
		else {
			 ans = arr[i].first + k - 1;
			break;
		}
	}
	cout<<ans<<endl;
 
		}
 
		
 
	}
	return 0;
}
