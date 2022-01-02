vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int N, long long int k) {
                          
        vector<long long >ans;
        int i = 0 ;
        int j = 0 ;
        queue<long long>q;
        while(j<N)
        {
            if((j-i+1) < k)
            {
                if(a[j]<0) q.push(a[j]) ;
                j++ ;
             }
            else if((j-i+1) == k)
            {
                  if(a[j]<0)
                  q.push(a[j]) ;
                  
                if(q.empty()) 
                ans.push_back(0) ;
                
                else 
                {
                       ans.push_back(q.front()) ;
                        if(a[i] == q.front()) 
                        q.pop() ;
                 }
                      i++ ; j++ ;
            }
        }
        return ans ;
        
 }
