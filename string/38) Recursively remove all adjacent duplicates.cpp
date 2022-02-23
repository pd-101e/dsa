class Solution{
    public:
    
    void solve(int idx , string &s)
    {
        if(s.length() -1 == idx )
        {
            return ;
        }
        if(s[idx] == s[idx+1])
        {
            s.erase(s.begin()+idx);
            solve(idx,s);
        }
        else {
            solve(idx+1,s);
        }
        return;
    }
    
    
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        solve(0,s);
        return s;
        
        
        
    }
};
