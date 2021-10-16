class Solution {
public:
    vector<string>ans;
    unordered_map<string,int>mp;
    void removeinvalid(int mra , string s)
    {
        
        
        if(mp[s]!=0)//for checking that string is already exist in map or not
        return;
    else
        mp[s]++;
    
    if(mra==0)
    {
        int mrn=getmin(s);
        if(mrn==0)
        {   
            string temp = s;
            ans.push_back(temp);
        }
        return;
    }
        
        int n = s.length();
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i]=='(' or s[i]==')')
            {
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            removeinvalid(mra-1,left + right);
            }
        }
        return;
    }
    
    int getmin(string s)
    {
        int n = s.length();
        stack<char>st;
        for(int i= 0 ; i<n ; i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    st.push(s[i]);
                }
                else if(st.top() == ')')
                {
                    st.push(s[i]);
                }
                else if(st.top()=='(')
                {
                    st.pop();
                }
            }
        }
        return st.size();
    }
    vector<string> removeInvalidParentheses(string s) {
        int mra = getmin(s);
        
        removeinvalid(mra,s);
        
        return ans;
    }
};
