

class Solution {
public:
    
    
    
    // iterative approach
   
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int profit = 0 ;
        if(n==0)
        {
            return profit;
        }
        int prev = prices[0];
        for(int i = 0 ; i<n ; i++)
        {
            if(prices[i] < prev)
            {
                prev = prices[i];
            }
            if(prices[i] > prev)
            {
                profit = max(profit,prices[i] - prev);
            }
        }
        return profit;
        
    }
    
    
    
    
};





// dp approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit=0;
        int minvalue=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            minvalue=min(minvalue,prices[i]);
            profit=max(profit,prices[i]-minvalue);
        }
        
        return profit;
        
    }
};

