
class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        
        int n = nums.size();
        int a[n+1];
        for(int i =1 ; i<=n ; i++)
        {
            a[i] = nums[i-1];
        }
        // 1st we store the number spaces for each 
        int space[n+1][n+1];
        int ls[n+1][n+1];
        int c[n+1];
        
        for(int i = 1 ; i<=n ; i++)
        {
            space[i][i] = k - a[i];
            for(int j = i+1 ; j<=n ; j++)
            {
                space[i][j] = space[i][j-1] - a[j] - 1;
            }
            
        }
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j =  i ; j<=n ; j++)
            {
                if(space[i][j] < 0 )
                {
                    ls[i][j] = INT_MAX;
                }
                else if(j==n and space[i][j]>0)
                {
                    ls[i][j] = 0;
                }
                else {
                    ls[i][j] = space[i][j]*space[i][j];
                }
            }
        }
        c[0] = 0;
        for(int i = 1 ; i<=n ; i++)
        {
            c[i] = INT_MAX;
            for(int j = 1 ; j<=i ; j++)
            {
                if(c[j-1]!=INT_MAX and ls[j][i] != INT_MAX )
                {
                    c[i] = min(c[i],c[j-1] + ls[j][i] );
                }
            }
        }
        
        return c[n];
        
    } 
};
