#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m , n;
        cin>>m>>n;
        m-- ;
        n--;
        
        int x[m] , y[n];
        for(int i = 0 ; i<m ; i++)
        {
            cin>>x[i];
        }
        for(int i = 0 ; i<n ; i++)
        {
            cin>>y[i];
        }
        
        int ans = 0 ;
        int hz = 1;
        int ver = 1;
        
        sort(x , x+m , greater<int>() );
        sort(y , y+n , greater<int>() );
        
        int i = 0 ;
        int j = 0 ;
        while (i<m and j<n) {
            if(x[i] > y[j])
            {
                ans += x[i]*ver;
                hz++;
                i++;
            }
            else {
                ans += y[j]*hz;
                ver++;
                j++;
            }
        }
        while(i<m)
        {
            ans += x[i]*ver;
            hz++;
            i++;
        }
        while(j<n)
        {
            ans += y[j]*hz;
            ver++;
            j++;
        }
        cout<<ans<<endl;
        
        
    }
}
