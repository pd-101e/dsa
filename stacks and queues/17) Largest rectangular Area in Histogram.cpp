class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<long long>nsl(long long arr[], int n)
    {
        long long pseudo = -1;
        vector<long long>ans;
        stack<pair<long long , long long>>s;
        for(int i = 0 ; i< n ; i++)
        {
            if(s.size() == 0 )
            {
                ans.push_back(pseudo);
                
            }
            else if(s.size() != 0  and s.top().first < arr[i])
            {
                ans.push_back(s.top().second);
            }
            else if(s.size() != 0 and s.top().first >= arr[i])
            {
                while(s.size() != 0 and s.top().first >= arr[i])
                {
                    s.pop();
                }
                if(s.size() == 0 )
                {
                ans.push_back(pseudo);
                }
                else 
                {
                    ans.push_back(s.top().second);
                }
            }
            
            s.push({arr[i],i});
        }
        return ans ;
        
    }
    
    
    vector<long long>nsr(long long arr[], int n)
    {
        long long pseudo = n;
        vector<long long>ans;
        stack<pair<long long , long long >>s;
        for(int i = n-1 ; i>=0 ; i--)
        {
            if(s.size() == 0 )
            {
                ans.push_back(pseudo);
                
            }
            else if(s.size() != 0  and s.top().first < arr[i])
            {
                ans.push_back(s.top().second);
            }
            else if(s.size() != 0 and s.top().first >= arr[i])
            {
                while(s.size() != 0 and s.top().first >= arr[i])
                {
                    s.pop();
                }
                if(s.size() == 0 )
                {
                ans.push_back(pseudo);
                }
                else 
                {
                    ans.push_back(s.top().second);
                }
            }
            
            s.push({arr[i],i});
        }
        reverse(ans.begin(), ans.end());
        return ans ;
    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long>left = nsl(arr,n);
        vector<long long>right = nsr(arr,n);
        vector<long long>width;
        for(int i = 0 ; i<left.size() ; i++)
        {
            width.push_back(right[i] - left[i] - 1);
        }
        vector<long long>area;
        for(int i = 0 ; i<width.size() ; i++)
        {
            area.push_back(width[i] * arr[i]);
        }
        long long maxx = LONG_MIN ;
        for(int i = 0 ; i<area.size() ; i++)
        {
            maxx = max(maxx,area[i]);
        }
        return maxx;
        
    }
};
