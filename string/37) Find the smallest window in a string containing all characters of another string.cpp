class solution{

    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int i = 0 ;
        int j = 0 ;
        int start = 0 ;
        int minl = INT_MAX;
        unordered_map<char,int>mp;
        for(auto x:p)
        {
            mp[x]++;
        }
        
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
                    minl = min(minl,j-i+1);
                    start = i;
                }
                while(count == 0)
                {
                    if(minl > j-i+1)
                     {
                         minl = min(minl,j-i+1);
                          start = i;
                    }
                    if(mp.count(s[i])!=0)
                    {
                         mp[s[i]]++;
                        if(mp[s[i]] == 1)
                        {
                          count++;
                         }
                    }
                    i++;
            }
        }
        
        
        
        
    }
    if(minl == INT_MAX)
    return "-1";
    else return s.substr(start,minl);
    }
};
