#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int w , h , n ;
        cin>>w>>h>>n;
        vector<int>width;
        vector<int>height;
        width.push_back(0);
        height.push_back(0);
        
        while(n--)
        {
            int x , y;
            cin>>x>>y;
            
            width.push_back(x);
            height.push_back(y);
        }
        width.push_back(w+1);
        height.push_back(h+1);
        
        sort(height.begin(),height.end());
        sort(width.begin(),width.end());
        
        int mw = 0 ;
        int mh = 0 ;
        
        for(int i =0; i<width.size() -1 ; i++)
        {
            mw = max(mw, abs(width[i+1] - width[i] - 1));
            mh = max(mh , abs(height[i+1] - height[i] - 1));
        }
//        cout<<mw<<" "<<mh<<" "<<endl;
        cout<<mh * mw << endl;
        
        
        
    }
}
