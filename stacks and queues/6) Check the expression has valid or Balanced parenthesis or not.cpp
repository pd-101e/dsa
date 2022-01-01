class Solution
{
    public:
    
    //Function to check if brackets are balanced or not.
    
    bool ismatching(char a , char b)
    {
        return ( (a=='{'&&b=='}')||(a=='('&&b==')')||(a=='['&&b==']'));
    }
    
    bool ispar(string str)
    {
        // Your code here
        stack<char>s;
        
        for(auto x:str)
        {
            if(x=='{'||x=='('||x=='[')
            s.push(x);
            else
            {
                if(s.empty()==true)
                {
                    return false;
                }
                if(ismatching(s.top(),x)==false)
                return false;
                
                else
                s.pop();
            }
        }
        if(s.empty()==true)
        {
            return true;
        }
        
    }
    


};
