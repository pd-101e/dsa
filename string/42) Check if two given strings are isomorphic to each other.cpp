// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s1, string s2)
    {
        
        // Your code here
        int n = s1.length();
        int m = s2.length();
        if(n!=m)
        {
            return false;
        }
        int m1[256] = {0};
        int m2[256] = {0};
        
        for(int i = 0 ; i<n ; i++)
        {
            if(m1[s1[i]] == 0 and m2[s2[i]] == 0)
            {
                m1[s1[i]] = s2[i];
                m2[s2[i]] = s1[i];
            }
            else if(m1[s1[i]] != s2[i])
            {
                return false;
            }
            
        }
        return true;
        
        
    }
};

