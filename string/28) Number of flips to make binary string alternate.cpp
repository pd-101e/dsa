int minFlips (string S)
{
    // your code here
    // there are two sequence in which they are made
    
    int c1 = 0 ;
    int c2 = 0 ;
    for(int i = 0 ; i<S.length() ; i++)
    {
        // flips to make the sequence
        //i.e 101
        
        if(i & 1 and S[i] == '0') c1++;
        if(i%2 == 0 and S[i] == '1')c1++;
        
        //i.e 010
        if(i&1 and S[i] == '1')c2++;
        if(i%2 == 0 and S[i] == '0')c2++;
        
    }
    int ans  = min(c1,c2);
    return ans;
    
}
