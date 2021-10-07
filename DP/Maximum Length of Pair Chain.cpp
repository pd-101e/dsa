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
