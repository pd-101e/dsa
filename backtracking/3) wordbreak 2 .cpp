//leetcode
class Solution {
public:
    
    vector<string>res;
    
    void solve(int index , unordered_set<string>&hash , string &s , string ans )
{
    if(index == s.length())
    {
        ans.pop_back();
        res.push_back(ans);
        return;
    }
    
    for(int i = index; i<s.length(); i++)
    {
        string word = s.substr(index,i - index + 1);
        
        if(hash.count(word) == 1)
        {
            solve(i + 1,hash , s, ans + word + " ");
        }
        
    }
    return;
    
}
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        unordered_set<string>hash;
        for(int i = 0 ; i<dict.size() ;i++)
        {
            hash.insert(dict[i]);
        }
        
        string ans = "";
        solve(0,hash,s,ans);
        return res;
    }
};


//----------------
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
