
int countRev (string s)
{
    // your code here
    int open = 0;
    int close = 0;
    stack<char>st;
    int n = s.size();
    if(n & 1) { // odd length for even last bit is zero
        return -1;
    }
    for(auto x:s)
    {
        if(x == '{')
        {
            st.push(x);
            open++;
        }
        else if(x == '}' and st.empty() == false)
        {
            if(st.top() == '{')
            {
                st.pop();
                open--;
            }
        }
        else {
            // remember this thing , this scope
            close++;
        }
    }
    
    if(open & 1) 
    {
        open = open/2 + 1;
    }
    else {
        open = open/2;
    }
    if(close & 1)
    {
        close = close/2 + 1;
    }
    else {
        close = close/2;
    }
    
    return open + close;
    
    
    
}
