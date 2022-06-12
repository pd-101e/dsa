class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int sum1 = 0 ;
        int sum2 = 0 ;
        int sum3 = 0 ;
        
        for(int i = 0 ; i<N1 ; i++)
        {
            sum1 += S1[i];
        }
        for(int i = 0 ; i<N2 ; i++)
        {
            sum2 += S2[i];
        }
        
        for(int i = 0 ; i<N3 ; i++)
        {
            sum3 += S3[i];
        }
        
        int ans = 0 ;
        
        int i = 0 , j = 0 , k = 0 ;
        while(i<N1 and j<N2 and k<N3)
        {
            if(sum1 == sum2 and sum2 == sum3)
            {
                ans = sum1;
                return ans;
            }
            else if(sum1 >= sum2 and sum1 >= sum3)
            {
                sum1 -= S1[i];
                i++;
            }
            else if(sum2 >= sum1 and sum2 >= sum3)
            {
                sum2 -= S2[j];
                j++;
            }
            else if(sum3 >= sum1 and sum3 >= sum2)
            {
                sum3 -= S3[k];
                k++;
            }
        }
        
        return ans;
        
        
        
    }
};
