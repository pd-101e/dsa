/*
Here's the explanation -
Eg -
string=aaaabcc
max frequency(f) = 4
no. of spaces=f-1 = 3
a_a_a_a
no. of character that can be put in those spaces = length of string(n) - max frequency(f)
So, if f-1<=n-f
return 1
else
return 0
*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t ;
	cin >>t;
	while(t--)
	{
	    string s ;
	    cin>>s;
	    int maxx = 0;
	    map<char,int>m;
	    for(auto x:s)
	    {
	        m[x]++;
	        maxx = max(maxx,m[x]);
	    }
	    if(maxx <= s.length() - maxx + 1)
	    {
	        cout<<1;
	    }
	    else cout<<0;
	    cout<<endl;
	    
	}
	return 0;
}
