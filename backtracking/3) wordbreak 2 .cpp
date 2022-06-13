class Solution{
public:

    vector<string>res;
    
    void wordbreak(int i , vector<string>&dict, string s ,string ans)
    {
        if(i == s.length())
        {
            ans.pop_back();
            res.push_back(ans);
            return ;
        }
        string word = "";
        for(int j = i ; j<s.length() ; j++)
        {
            word = word + s[j];
            for(int m = 0 ; m<dict.size() ; m++)
            {
                if(dict[m] == word)
                {
                    wordbreak(j+1,dict,s,ans + word + " ");
                    break;
                }
            }
        }
        return ;
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        
        string ans = "";
        wordbreak(0,dict,s,ans);
        return res;
        
    }
};
