class solution{
  public:
    string findSubString(string s)
    {
        // Your code goes here   
        string t = "";
        unordered_set<char>st;
        for(auto x:s)
        {
            st.insert(x);
        }
        unordered_map<char,int>mp;
        
        for(auto x:st)
        {
            mp[x]++;
            t += string(1,x);
        }
        int i = 0 ;
        int j = 0 ;
        int minl = INT_MAX;
        int start = 0;
        
        int count = mp.size();
        if(mp.count(s[j])!=0)
        {
            mp[s[j]]--;
            if(mp[s[j]] == 0)
            {
                count--;
            }
        }
        while(j<s.length())
        {
            if(count > 0)
            {
                j++;
                if(mp.count(s[j])!=0)
                     {
                         mp[s[j]]--;
                         if(mp[s[j]] == 0)
                            {
                              count--;
                             }
                         }
            }
            else if(count == 0)
            {
                if(minl > j-i+1)
                {
                    start = i;
                    minl = j-i+1;
                }
                while(count == 0)
                {
                    if(mp.count(s[i])!=0)
                    {
                        mp[s[i]]++;
                        if(mp[s[i]] == 1)
                        {
                            count++;
                            if(minl > j-i+1)
                             {
                                 start = i;
                                minl = j-i+1;
                            }
                        }
                    }
                    i++;
                }
            }
            
        }
        
        return s.substr(start,minl);
        
        
    }
};
