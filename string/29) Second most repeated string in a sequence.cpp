// my approach
class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string , int>mp;
        for(int i = 0 ; i<n ; i++)
        {
            mp[arr[i]]++;
        }
        map<int,string>s;
        for(auto x:mp)
        {
            s.insert({x.second,x.first});
        }
        
       vector<string>a;
       
        for(auto x:s)
        {
           a.push_back(x.second);
            
        }
       a.pop_back();
       string temp = a.back();
       return temp;
        
        
    }
};


// gfg soln
class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map <string, int> m;
    
        for (int i = 0; i < n; ++i)
            m[arr[i]]++;
    
    
        // first and second most occurred strings
        int mx1 = INT_MIN, mx2 = INT_MIN;
    
        for (auto i : m)
        {
            // we got a new mx1
            // hence, current mx1 is stored in mx2
            if (i.second > mx1)
            {
                mx2 = mx1;
                mx1 = i.second;
            }
    
            // we got a new mx2
            else if (i.second > mx2 and i.second != mx1)
            {
                mx2 = i.second;
            }
        }
        
        for (auto i : m)
            if (i.second == mx2)
                return i.first;
        
        return "";
    }
    // Contributed By: Pranay Bansal

};
