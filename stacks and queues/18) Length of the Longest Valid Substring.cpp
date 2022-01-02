class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int n = s.length();
        int res = 0 ;
        stack<int>st;
        st.push(-1);
        for(int i =0 ; i<n ; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else {
                if(!st.empty())
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    res = max(res,i - st.top());
                }
                else st.push(i);
                
            }
        }
        return res;
    }
};
