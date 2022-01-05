/*
Approach: Initialize count = 0 and traverse the string character by character and keep track of the number of 0s and 1s so far, whenever the count of 0s and 1s become equal increment the count.
As in the given question, if it is not possible to split string then on that time count of 0s must not be equal to count of 1s then return -1 else print the value
of count after the traversal of the complete string.
*/



// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count
// of maximum substrings str
// can be divided into
int maxSubStr(string str, int n)
{
    int zero = 0 ;
    int one = 0;
    int count = 0;
    for(int i = 0 ; i<n ; i++)
    {
        if(str[i] == '0') // remember string check the char
        {
            zero++;
        }
        else {
            one++;
        }
        if(one == zero)
        {
            count++;
        }
        
    }
    if(count == 0)
    {
        return -1;
    }
    else return count;
   
}

// Driver code
int main()
{
    string str = "0111100010"; // o/p 3
    int n = str.length();

    cout << maxSubStr(str, n);

    return 0;
}



// used reccursion, can be memoized, zyada hi dimag laga liya simple se question mein
// O(n*n) once memoized
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool balenced (string s, int i, int j) {
    int c = 0;
    for (int k=i; k<=j; k++) {
        c += s[k]=='1' ? 1 : -1;
    }
    return c==0;
}

int splits (string s, int i, int j) {
    if (i>=j) return -1;
    if (i==j-1) {
        if (s[i] != s[j]) return 1;
        else return -1;
    }
    
    int split = 0;
    for (int ptr=i; ptr<j; ptr++) {
        int s1 = splits(s, i, ptr);
        int s2 = splits(s, ptr+1, j);
        split = max (split, s1+s2);
    }
    if (split) return split;
    if (balenced(s, i, j)) return 1;
    else return -1;
}

int main() {
    
    string s = "0100110101";
    cout << splits (s, 0, s.size()-1);
}

// Simple O(n) approach
// keep a counter, increment for 1 decrement for 0, as counter becomes 0 increment result
// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/
