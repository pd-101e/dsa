#include <bits/stdc++.h>
using namespace std;

int solve(int i , int j , char ch[6][6] , string &s , int size , int index)
{
   
    if(i<0 or j<0 or i>=6 or j>=6 or ch[i][j]!=s[index])
    {
        return 0; // we return 0
    }
    
    if(index == size-1)
        return 1; // we found the string hence we return 1
    
        char temp = s[index];
        int found = 0 ;
        ch[i][j] = '0';
        found += solve(i+1,j,ch,s,size,index+1);
        found += solve(i,j+1,ch,s,size,index+1);
        found += solve(i-1,j,ch,s,size,index+1);
        found += solve(i,j-1,ch,s,size,index+1);
        ch[i][j] = temp; // back track
    
  
    
    return found;
    
    
}

int main()
{
    string s = "GEEKS";
    int size = s.length();
    char ch[6][6]  = {
        {'D','D','D','G','D','D'},
        {'B','B','D','E','B','S'},
        {'B','S','K','E','B','K'},
        {'D','D','D','D','D','E'},
        {'D','D','D','D','D','E'},
        {'D','D','D','D','D','G'}
    };
    int ans = 0 ;
    for(int i = 0 ; i<6 ; i++ )
    {
        for(int j = 0 ; j<6 ; j++)
        {
            ans += solve(i,j,ch,s,size,0);
        }
    }
    cout<<endl<<ans<<endl;
    
    return 0;
}
