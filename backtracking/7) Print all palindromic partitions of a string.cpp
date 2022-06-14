class Solution {
public:
    
    
    vector<vector<string>>res;
  
  bool ispalindrome(string word )
  {
      int low = 0 ;
      int high = word.length() - 1 ;
      
      while(low < high)
      {
          if(word[low] != word[high])
          return false;
          
          low++;
          high--;
          
      }
      
      return true;
      
  }
  
  void solve(int index , string &s , vector<string>ans)
  {
      if(index == s.length())
      {
          res.push_back(ans);
          return;
      }
      
      for(int i = index ; i<s.length() ; i++)
      {
          string word = s.substr(index , i - index + 1);
          
          if(ispalindrome(word))
            {
                ans.push_back(word);
                solve(i+1 , s , ans);
                ans.pop_back();
            }
                  
      }
      return;
      
  }
    
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        solve(0,s , ans);
        
        return res;
    }
};
