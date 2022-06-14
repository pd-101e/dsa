class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>>res;
    set<vector<int>>s;
    
    void solve(vector<int>&arr, int index, int sum , vector<int>&ans)
    {
        if(sum == 0)
        {
            if(s.count(ans) == 0)
            {
                sort(ans.begin(), ans.end());
                res.push_back(ans);
                s.insert(ans);
            }
        }
        
        if(index == arr.size())
        {
            return;
        }
        
        if(arr[index] <= sum)
        {
            ans.push_back(arr[index]);
            solve(arr,index ,sum - arr[index] ,ans );
            ans.pop_back();
        }
        solve(arr,index + 1 , sum , ans);
        return;
        
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>ans;
        unordered_set<int>st;
        // by rempoving the sublicates its solve the problem of TLE
        for(int i = 0; i<A.size() ; i++)
        {
            st.insert(A[i]);
        }
        A.clear();
        for(auto x:st)
        {
            A.push_back(x);
        }
        
        
        sort(A.begin(),A.end());
        solve(A,0,B,ans);
        sort(res.begin(),res.end());
        return res ;
        
        
    }
};
