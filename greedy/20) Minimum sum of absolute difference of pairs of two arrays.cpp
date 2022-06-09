class Solution{
public:
    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        // first sort both of them 
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        long long minsum = 0 ;
        
        for(int i = 0 ; i<N ; i++)
        {
            minsum += abs(A[i] - B[i]);
        }
        
        return minsum;
        
    }
};
