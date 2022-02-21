int majorityElement(int a[], int n)
{
        
    // your code here
    //find the candidate moore's VOting algo rithm
    
    int res = 0 , count = 1;
    for (int i= 1; i<n;i++)
    {
        if(a[res]==a[i])
        {
            count ++;
        }
        else count--;
        if (count == 0 )
        {
            count=1;
            res = i ;
        }
    }
    
    count = 0 ;
    //checke the candidate element res id n/2 or not 
    for (int i= 0 ; i<n; i++)
    {
        if (a[res]==a[i])
        count++;
        
    }
    if(count > n/2)
    {
        return a[res];
    }
    return -1;
        
}
