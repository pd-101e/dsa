#include <bits/stdc++.h>

#define int long long int

using namespace std;

int32_t main()
{
    int t ;
    cin>>t;
   
    while(t--)
    {
        int n ;
        cin>>n;
        int ones = 0 ;
        int arr[n];
        for(int i = 0 ; i<n ; i++)
        {
            int a ;
            cin>>a;
            if(a == 1)
                ones++;
            arr[i] = a;
        }
        
        for(int i =0; i<ones ; i++)
        {
            cout<<"1"<<" "; // 1 handled
        }
        sort(arr , arr + n , greater<int>());
        
        if(n-ones == 2 and arr[0] == 3 and arr[1] == 2) //exception case
        {
            cout<<"2 3"<<endl;
        }
        else {
            for(int i =0; i<n - ones ; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
        
    }
    
    return 0;
}
