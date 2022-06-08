class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        sort(X.begin(),X.end(),greater<int>()); // we have to sort in descending order
        sort(Y.begin(),Y.end(),greater<int>());
        
        int ans = 0 ;
        // we will use greedy approach 
        // Total_cost = Total_cost + edge_cost * total_pieces
        // first cut the max cost and then as total pieces is less also so accordig to formula
        
        int i = 0 ;
        int j = 0 ;
        int hz = 1;// at satarting ther is 1 piece of block
        int ver = 1;
        
        while(i<M and j<N)
        {
            if(X[i] > Y[j])
            {
                ans += X[i]*ver; // whenver we cut in verticac direction
                hz++; // horizontal will increase by one and 
                i++;
            }
            else {
                ans += Y[j]*hz;
                ver++; // vice versa
                j++;
            }
            
        }
        while(i<M)
        {
            ans += X[i]*ver;
                hz++;
                i++;
        }
        while(j<N)
        {
            ans += Y[j]*hz;
                ver++;
                j++;
        }
        return ans;
        
    }
};
