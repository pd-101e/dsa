/*

Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1. Start Time
2. Finish Time
3. Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input Format:
The first line of input contains an integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Constraints:
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Output Format:
Output one integer, the maximum profit that can be achieved.
Sample Input 1
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output 1
250

*/


/// nlogn solution
#include<bits/stdc++.h>
using namespace std;

struct job{
    int start,finish,profit;
};

bool mycmp(job a , job b)
{
    return a.finish < b.finish;
}

int search(job arr[], int n ) // remember this binary search good imp 
{
    int low = 0 , high = n-1;
    int k = arr[n].start;
    int res = INT_MAX;
    while(low<=high)
    {
        int mid = low + (high - low )/2;
        if(arr[mid].finish <= k )
        {
            if(arr[mid+1].finish <= k )
            	low = mid + 1 ;
            else 
                return mid;
            
        }
        
        else {
            high = mid-1 ;
        }
    }
    return -1 ;
}

int solve(job arr[], int n )
{
    int profit[n];
    sort(arr,arr+n,mycmp);
    profit[0] = arr[0].profit;
    int inc = arr[0].profit;
    int exc = 0 ;
    
    for(int i = 1 ; i<n ; i++)
    {
        int latesNCprofit = 0 ;
        
        int res =  search(arr,i);
        if(res!=-1)
        {
            latesNCprofit = profit[res];
        }
        
        // for(int j = i-1 ; j>=0 ; j--)
        // {
        //     if(arr[j].finish <= arr[i].start)
        //     {
        //          latesNCprofit = profit[j];
        //         break;
        //     }
        // }
        int inc = arr[i].profit + latesNCprofit;
            // my rpofit + lates non conflictiong profit
        int exc = profit[i-1];
        profit[i] = max(inc,exc);
    }
    return profit[n-1];
    
}


int main(){
    
    // write your code here
    int n ;
    cin>>n;
    job arr[n];
    for(int i = 0 ; i<n ; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[i].start = a;
        arr[i].finish = b;
        arr[i].profit = c;
        
    }
    cout<<solve(arr,n);
    return 0;
}






// bigo of n^2 solution
#include<bits/stdc++.h>
using namespace std;

struct job{
    int start,finish,profit;
};

bool mycmp(job a , job b)
{
    return a.finish < b.finish;
}



int solve(job arr[], int n )
{
    int profit[n];
    sort(arr,arr+n,mycmp);
    profit[0] = arr[0].profit;
    int inc = arr[0].profit;
    int exc = 0 ;
    
    for(int i = 1 ; i<n ; i++)
    {
        int latesNCprofit = 0 ;
        
        for(int j = i-1 ; j>=0 ; j--)
        {
            if(arr[j].finish <= arr[i].start)
            {
                 latesNCprofit = profit[j];
                break;
            }
        }
        int inc = arr[i].profit + latesNCprofit;
            // my rpofit + lates non conflictiong profit 
        int exc = profit[i-1];
        profit[i] = max(inc,exc);
    }
    return profit[n-1];
    
}


int main(){
    
    // write your code here
    int n ;
    cin>>n;
    job arr[n];
    for(int i = 0 ; i<n ; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[i].start = a;
        arr[i].finish = b;
        arr[i].profit = c;
        
    }
    cout<<solve(arr,n);
    return 0;
}
