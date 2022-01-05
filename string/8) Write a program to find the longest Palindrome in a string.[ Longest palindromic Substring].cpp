Class Solution{
   public:
  
  
    string longestPalin (string S) {
        // code here
        // for palindroem make every i'th element as center and expand it around
        
        // ho sakta hai palindromic string odd or even length ki ho to hum dono
        // ke according likhenge
        
         int maxx = 0 ;// to store final length of the. substring
         string res ; // to store the final string
        int n = S.length();
        for(int i = 0 ; i<n ; i++)
        {
            // for odd
            int l = i;
            int r = i;
            
            while( l>=0 and r<n and S[l] == S[r])
            {
                int curr_len = r-l+1; // focus on length
                
                if(curr_len > maxx)
                {
                    maxx = curr_len;
                    res = S.substr(l,r - l + 1);
                    
                }
                l--;
                r++;
            }
            
           
            
            // for even
     
            l = i;
            r = i+1;
            while(l>=0 and r<n and S[l] == S[r])
            {
                int curr_len = r-l+1;
                
                if(curr_len > maxx)
                {
                    maxx = curr_len;
                    res = S.substr(l,r - l + 1);
                    
                }
                l--;
                r++;
            }
            
            
            
            
        }
        return res;
        
    }
};
