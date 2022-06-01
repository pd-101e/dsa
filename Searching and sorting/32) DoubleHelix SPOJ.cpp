/*

 double helix question
 two pointer approach

 algo
 1) track the sum of two untill the bridge is come and after that
 whenenver we get the bridge we will take maximum of it and add then add the bridge
 adfter following this algo we will get what we need
 
 
 */


#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        int n ;
        cin>>n;
        if(n==0) break;
        else {
            int a[n];
            for(int i = 0 ; i<n ; i++)
            {
                cin>>a[i];
            }
            int m ;
            cin>>m;
            int b[m];
            for(int i = 0; i<m ; i++)
            {
                cin>>b[i];
            }
            int s1 = 0 , s2 = 0 ;
            int i = 0 , j = 0 ;
            int sum = 0 ;
            
            while(i<n and j<m)
            {
                if(a[i]<b[j])
                    s1 += a[i++];
                else if(b[j] < a[i])
                    s2 += b[j++];
                else if(a[i] == b[j])
                {
                    sum = sum + max(s1,s2) + a[i];
                    s1 = s2 = 0;
                    i++ ;
                    j++;
                }
            }
            while(i<n)
            {
                s1 += a[i++];
            }
            while(j<m)
            {
                s2 += b[j++];
            }
            sum = sum + max(s1,s2);
            cout<<sum<<endl;
            
        }
        
    }
}
