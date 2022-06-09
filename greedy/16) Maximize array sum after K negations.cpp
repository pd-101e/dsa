class Soluiton{
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        
        /*
        hum 1 element ke sath hum kitni bar bhi operetion karwa sakte hai
        */
        
        long long int sum = 0 ;
        int neg = 0 ;
        int pos = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            if(a[i] < 0 )
            neg++;
            else 
            {
                pos++;
            }
        }
        
        sort(a , a+n  );
        int i = 0 ;
        while(i<n and k!=0 and neg != 0)
        {
            a[i] = -1 * a[i];
            i++;
            neg--;
            k--;
        }
        // int j = n-1;
        // while(j>=0 and k!=0 and pos!=0)
        // {
        //     a[i] = -1 * a[i];
        //     j--;
        //     pos--;
        //     k--;
        // }
        
        if(k!=0)
        {
            sort(a,a + n);
            if(k%2 != 0)
            {
                a[0] = -1 * a[0];
            }
        }
        
        for(int i = 0 ; i<n ; i++)
        {
            sum += a[i];
        }
        return sum;
        
    }
};
