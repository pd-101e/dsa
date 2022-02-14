//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    
    
    int dp[100001][3][2];
    int solve(int index , int n , vector<int>&prices , int k , bool buy)
    {
        if(index>=n)
        {
            return 0;
            
        }
        if(k<=0)
        {
            return 0;
        }
        
        if(dp[index][k][buy]!=-1)
        {
            return dp[index][k][buy];
        }
        int option1 , option2;
        if(buy)
        {
            option1 = -prices[index] + solve(index+1,n,prices,k,!buy);
        }
        else {
            option1 = prices[index] + solve(index+1,n,prices,k-1,!buy);
            
        }
        
        option2 = solve(index+1,n,prices,k,buy);
        int res = max(option1 , option2);
        dp[index][k][buy] = res;
        return res;
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,prices,2,true);
    }
};
