#define mod 1000000007
class Solution{
public:
    int memo [1001][801];
    
    int nCr(int n, int r){
    
        memset(memo, -1, sizeof(memo));
        
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=r; j++) {
                if (j==0) memo[i][j] = 1;
                else if (i<j) memo[i][j] = 0;
                else {
                    memo[i][j] = (memo[i-1][j] + memo[i-1][j-1])%mod;
                }
            }
        }
        return memo[n][r];
    }
};
