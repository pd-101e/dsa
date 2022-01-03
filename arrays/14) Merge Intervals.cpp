class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int left = intervals[0][0];
        int right = intervals[0][1];
        int n= intervals.size();
        for(int i = 1 ; i<n ; i++)
        {
            if(right >= intervals[i][0])
            {
                if(right < intervals[i][1]) // handle this test case 
                    // intput :[[1,4],[2,3]] output : [[1,3]]
                right = intervals[i][1];
                
            }
            else {
                ans.push_back({left,right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        ans.push_back({left,right});
        return ans;
        
        
        
    }
};
