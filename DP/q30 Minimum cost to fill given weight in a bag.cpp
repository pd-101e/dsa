// My approach : unbounded knapsack



using namespace std;
//Position this line where user code will be pasted.

class Solution{
		
public:
	int minimumCost(int cost[], int N, int W) 
	{ 
	    int dp[N+1][W+1];
	    memset (dp, -1, sizeof(dp));
	    for (int i=0; i<=N; i++) dp[i][0] = 0;
	    
	    for (int i=1; i<=N; i++) {
	        for (int j=1; j<=W; j++) {
	            dp[i][j] = dp[i-1][j]; // first we have come with the non included case when last element is not included
	            
	            if (cost[i-1]!=-1 && i<=j && dp[i][j-i] != -1) { // as tabulationn means that recursion is already soved we are just retriving the recursed solution value 
	                int consider = cost[i-1] + dp[i][j-i];
	                if (dp[i][j]==-1) dp[i][j] = consider;
	                else dp[i][j] = min (dp[i][j], consider);
	            }
	        }
	    }
	    return dp[N][W];
	} 
};







/// not correct recurstion jsut for study basis reference only
class Solution{
		
public:
        
        int solve(int cost[],int n,int w)
        {
            if(n==0)
	    return -1;
	    if(w==0)
	    return 0;
	    
	    int temp = solve(cost , n-1 , w );
	    
	    if(cost[n-1]!=-1 and n<=w )
	    {
	    
	    int temp2 = solve(cost , n , w - n);
	    
	    if(temp2!=-1 and temp==-1)
	    {int consider;
	         consider = cost[n-1] + temp2;
	        return consider;
	    }
	    else {
	        return min(cost[n-1] + temp2,temp);
	    }
	    
	    }
	    else return temp;
	    

}

	int minimumCost(int cost[], int n, int w) 
	{ 
	    
	    return solve(cost,n,w);
	} 
};

