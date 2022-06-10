class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin() , Arr.end() );
        
        long long int ans = 0 ; // use long long int
        long long int sum = 0 ;
    
        if(N==1)
        {
            return 1;
        }
        for(int i = 0 ; i<N ; i++)
        {
            sum += Arr[i];
            
        }
        if(sum == 0) // nice logic
        return N;
        
        int i = N-1;
        long newsum = 0 ;
        while(true)
        {
            newsum += Arr[i];
            sum -= Arr[i];
            i--;
            ans++;
            if(newsum > sum)
            {
                break;
            }
        }
        
        
        return ans;
    }
};
