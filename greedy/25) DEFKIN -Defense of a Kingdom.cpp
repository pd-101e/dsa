/*
From what i understood, the rectangle will be formed by making of the grey lines, i.e even if the first one and second 
piece had only one row between them and 8 columns between them, imagine gray lines going from both of those positions to the 
end of the whole diagram and since the rectangle created by the grey lines and not those pieces it will be formed by either two
pieces or a piece and a wall, thus the maximum length and maximum width will form at least one rectangle, if that makes sense.
*/

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
