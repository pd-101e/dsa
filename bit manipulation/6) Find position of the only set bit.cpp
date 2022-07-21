class Solution{
public:
    int findPosition(int n) {
        // code here
        int count = 0 ;
        bool flag = false;
        int pos = 0 ;
        while(n)
        {
            if(n & 1)
            {
                count++;
                
            } 
            pos++;
            n = n>>1;
        }
        if(count == 1)
        return pos;
        else return -1;
    }
    };
