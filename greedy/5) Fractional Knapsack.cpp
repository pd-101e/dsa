/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    // static bool mycmp(Item a , Item b)
    // {
    //     double val1 = (double)(a.value/a.weight); // do not put brackets man
    //     double val2 = (double)(b.value/b.weight);
    //     return val1 > val2;
    // }
    
    // double fractionalKnapsack(int W, Item arr[], int n)
    // {
    //     // Your code here
        
    //     sort(arr,arr+n,mycmp);
    //     int mysum = 0 ;
    //     double total = 0.0;
    //     for(int i = 0 ; i<n ; i++)
    //     {
    //         if(mysum + arr[i].weight <= W)
    //         {
    //             total += arr[i].value;
    //             mysum += arr[i].weight;
    //         }
    //         else {
                
    //             double frac = (double)arr[i].value/arr[i].weight;
    //         total += (double)(W - mysum) * frac;
    //             break;
    //         }
    //     }
        
    //     return total;
    
    static bool mycmp(Item a , Item b)
    {
        double val1 = (double)a.value/a.weight;
        double val2 = (double)b.value/b.weight; // my mistake do nor put a.value/a.weight in brackets
        return val1 > val2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,mycmp);
        
        double total = 0;
        
        int currw = 0;
        for(int i = 0 ; i<n; i++)
        {
            if(arr[i].weight + currw <=W)
            {
                total += arr[i].value;
                currw += arr[i].weight;
            }
            else 
           { 
               
            total += (W-currw) * (double)arr[i].value/arr[i].weight;; //( maths only in Computer)
            //take an example we can do like this also 2*81/9 = 18
            break;
           }
        }
        return total;
        
        
    }
        
};
