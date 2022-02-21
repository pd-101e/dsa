// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here


#include<bits/stdc++.h>
using namespace std;

// int solve(vector<int>&arr , int n , int x)
// {
// 	int low = 0 ;
// 	int high = n-1;
// 	while(low<=high)
// 	{
// 		int mid = low +( high - low )/2;
// 		if(arr[mid] == x)
// 		{
// 			return mid;
// 		}
// 		else if(arr[mid] > x)
// 		{
// 			high = mid - 1;
// 		}
// 		else {
// 			low = mid + 1;
// 		}
// 	}
// 	return high;
// }

int main()
{
	int n ;
	cin>>n;
	int arr[n];
	for(int i = 0 ; i<n ; i++)
	{
		int x ;
		cin>>x;
		arr[i] = x;
	}
	sort(arr,arr+n);
	// presum
	int pre[n+1];
	pre[0] = 0;

	for(int i = 1 ; i<=n ; i++)
	{
		pre[i] = pre[i-1] + arr[i-1];
	}
	int t;
	cin>>t;
	while(t--)
	{
		int x ;
		cin>>x;
		int index = upper_bound(arr,arr+n,x) - arr;
		
		cout<<index<<" "<<pre[index];
		cout <<endl;
	}


}
