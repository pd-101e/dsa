
class Solution{
  public:
  vector<vector<string>>ans;
  
  bool solve(string s1 , string s2)
  {
      unordered_map<char,int>mp;
      for(int i = 0 ; i<s1.length() ; i++)
      {
          mp[s1[i]]++;
          mp[s2[i]]--;
      }
      for(auto x:mp)
      {
          if(x.second > 0)
          {
              return false;
          }
      }
      return true;
      
      
      
  }
  
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        bool dp[n];
        for(int i = 0 ; i<n ; i++)
        {
            dp[i] = false;
        }
        
        for(int i = 0 ; i<n ; i++)
        {
            vector<string>res;
            string temp = string_list[i];
            for(int j = 0 ; j<n ; j++)
            {
                if(dp[j] == false)
                {
                if(solve(temp,string_list[j]))
                {
                    dp[j] = true;
                    res.push_back(string_list[j]);
                }
                }
            }
            // sort(res.begin(),res.end());
            if(res.size()!=0)
            ans.push_back(res);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


/// gfg solution 
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) 
    {
        vector<vector<string> > result;
    
        // hash map to maintain groups of anagrams
        unordered_map <string,vector<string> > umap; 
        
        for(int i =0; i<string_list.size(); i++ )
        {
            string s = string_list[i];
         
            // sort each string
            sort(s.begin(),s.end());
            
            // add original string to corresponding sorted string in hash map
            umap[s].push_back(string_list[i]);
        }
        for(auto itr= umap.begin(); itr!=umap.end(); itr++)
            result.push_back(itr->second);
        
        return result;
    }
};
