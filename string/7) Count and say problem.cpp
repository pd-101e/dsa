// my approach
class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
        {
            return to_string(1);
        }
        
        string s = countAndSay(n-1); //ye maan lo ki smaller input mujhe digit lake dedega
        string res = ""; 
        int len = s.length();
        int i = 0 ;
        int j = 0 ;
        int count = 0 ;
        while(i<len and j<len)
        {
            if(s[i] == s[j])
            {
                count++;
                i++;
                
            }
            else {
                res += to_string(count) + string(1,s[j]);
                count = 0;
                j = i;
            }
        }
        
        res += to_string(count) + string(1,s[len-1]);
        
        return res;
        
    }
};


// good one clean and neat
#include <bits/stdc++.h>
using namespace std;

string say (string s) {
    string result = "";
    for (int i=0; i<s.size(); ) {
        char letter = s[i];
        int count=0;
        while (i<s.size() && s[i]==letter) {
            count++; i++;
        }
        result += to_string (count) + letter;
    }
    return result;
}

string countAndSay(int n) {
    if (n==1) return "1";
    
    return say(countAndSay(n-1));
}

int main () {
    int n;
    cin>>n; 
    cout << countAndSay (n);
    return 0;
}
