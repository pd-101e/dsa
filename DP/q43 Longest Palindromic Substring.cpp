////     that commented code is my wrong approach


class Solution {
public:
    
    
    string lcs(string s1 , string s2 , int m , int n )
{
        // stack<pair<int,int>>st;
    int dp[m+1][n+1];
    for(int i = 0 ; i<=m ; i++)
    {
        for(int j= 0 ; j<=n ; j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]= 0 ;
            }
        }
        
    }
        int max = 0;
        string res = "";
    for(int i = 1 ; i<=m ; i++)
    {
        for(int j = 1 ; j<=n ; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                
                 if(dp[i][j]>max)
                    {
                        string temp = s1.substr(i-dp[i][j], dp[i][j]) ;
                        
                        string revtemp = string(temp.rbegin(),temp.rend());
                        if(revtemp==temp)
                        {
                            max = dp[i][j] ;
                            res = temp ;
                        }
                    }
                
                
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    
//         int mn = 0;
//         for(int i = 0 ; i<=m ; i++)
//         {
//             for(int j = 0 ; j<=n ; j++)
//             {
//                 if(dp[i][j]!=0)
//                 {
//                     if(mn<dp[i][j])
//                     {
//                         mn = dp[i][j];
//                         st.push({i,j});
//                     }
                    
//                 }
//             }
//         }
//         auto p = st.top();
//         int i = p.first;
//         int j = p.second;
//         cout<<endl<<i<<"   "<<j<<endl;
//         string ans = "";
//         bool flag = true;
//         while(i>0 and j>0 and dp[i][j]!=0)
//         {
            
            
//             if(flag)
//            { 
//                 if(dp[i][j]==1)
//                 flag = false;
//                 cout<<endl<<s1[i-1]<<endl;
//             ans.push_back(s1[i-1]);
//             i--;
//             j--;
//             }
            
//         }
        return res;
        
        
}

    
    
    string longestPalindrome(string s) {
        int m = s.length();
        string b = s;
         reverse(s.begin(),s.end());
        return lcs(s,b,m,m);
        
    }
};
