class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        int n = a.length();
        
        set<char>s;
        for(int i = 0 ; i<n ;i++)
        {
            s.insert(a[i]);
        }
        
        for(int i = 0 ; i<n ; i++)
        {
            s.erase(a[i]);
            if(s.empty()) break;
            auto it = s.begin();
            auto ch = *it;
            auto curr = a[i];
            if(curr > ch)
            {
                for(int j = 0 ; j<n ; j++)
                {
                    if(a[j] == ch )
                    {
                        a[j] = curr ;
                    }
                    else if(a[j] == curr)
                    {
                        a[j] = ch;
                    }
                }
                break;
            }
            
        }
        
        return a;
    }
    
};
