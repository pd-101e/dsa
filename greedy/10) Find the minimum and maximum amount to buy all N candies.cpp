class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies , candies + N);
        vector<int>v = {-1,-1};
        int maxx =0 ;
        int minn = 0;
        int sub = 0;
        for(int i = 0 ; i<N - sub ; i++)
        {
            minn += candies[i];
            sub += K;
        }
        int add = 0;
        for(int i = N-1 ; i>=0 + add ; i--)
        {
            maxx += candies[i];
            add += K;
        }
        
        v[0] = minn;
        v[1] = maxx;
        return v;
        
    }
};
