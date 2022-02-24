//*********** method 1
class solution{
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        //imp string balanced by swapping adjacent 
        
        int n = s.length();
        int ans = 0 ;
        int count = 0 ;
        vector<int>v;
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i] == '[')
            {
                v.push_back(i);
            }
        }
        
        int idx = 0 ;
        for(int i =0 ; i<n ; i++)
        {
            if(s[i] == '[')
            {
                count++;
                idx++;
            }
            else {
                count--;
                if(count <0 )
                {
                    ans += v[idx] - i;
                    swap(s[i],s[v[idx]]);
                    idx++;
                    count = 1;
                    
                }
            }
        }
        
        return ans ;
    }
};

//*********** method 2
class Solution {
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int n = s.length();
        int ans = 0 ;
        int open = 0 ;
        int close = 0 ;
        int fault = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i] == ']')
            {
                close++;
                fault = close - open;
            }
            else {
                open++;
                if(fault > 0)
                {
                    ans += fault;
                    fault--;
                }
            }
        }
        return ans ;
    }
};
