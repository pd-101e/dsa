// 1
static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        int res = 0;
        for (int i = 0, j = 0; j < n; j++) 
        {
            if (j == 0 || pairs[i][1] < pairs[j][0]) 
            {
                res++;
                i = j;
            }
        }
        return res;
    }
// 2
class Solution {
public:
    // can be solved by activation problem 
    // by changing the sorting now we sort with respect to 2nd ele by greedy approach
    static bool mycmp(const vector<int>&a , const vector<int>&b )
    {
        if(a[1] == b[1])
        {
            return a[0] < b[0];
        }
        else {
            return a[1] < b[1];
        }
       
    }
    
    int findLongestChain(vector<vector<int>>& arr) {
        
//         int n = pairs.size();
//         sort(pairs.begin(),pairs.end(),mycmp);
        
//         int prev = pairs[0][1] ;
//         int res = 1 ;
        
//         for(int curr = 1 ; curr<n ; curr++)
//         {
//             if(prev < pairs[curr][0])
//             {
//                 res++;
//                 prev = pairs[curr][1];
//             }
//         }
//         return res;

        int count = 1;
sort(arr.begin(),arr.end(),mycmp);
int prev = arr[0][1];
for(int curr = 1 ; curr<arr.size() ; curr++)
{
    if(prev < arr[curr][0])
    {
        prev = arr[curr][1];
        count++;
    }

}
return count;
        
        
    }
    
};

// 3
class Solution {
public:
    
    static bool mycmp(const vector<int>&a , const vector<int>&b )
    {
        if(a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else {
            return a[0] < b[0];
        }
        return false;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),mycmp);
        
        vector<int>dp(n,1);
        int res = 1;
        for(int i = 1 ; i<n ; i++)
        {
            dp[i] = 1;
            for(int j = 0 ; j<i ; j++)
            {
                if(pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                    
                }
                res = max(dp[i],res);
            }
        }
        
        return res;
        
        
    }
    
};
