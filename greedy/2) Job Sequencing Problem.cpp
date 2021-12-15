/*
keep int mind 
question lang int it taking 1 unit time for every job so we make the time line 
question lang 

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with job if and only if the job is completed by its deadline.



*/



/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool mycmp(Job &a , Job &b)
    {
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>ans;
        int result[n];
        bool visited[n];
        for(int i = 0 ; i<n ; i++)
        {
            visited[i] = false;
        }
        sort(arr,arr+n,mycmp);
        for(int i =0 ; i<n ; i++)
        {
            for(int j = min(n,arr[i].dead) - 1 ; j>=0 ; j--) // as based on zero indexing so -1
            {
                //from last available slot in visited and storing the job number in resul array
                if(visited[j] == false)
                {
                    visited[j] = true; // marking as discovered (to amke tarack of jobs slot)
                    result[j] = i;  //storing the jo number for future reference 
                    break; // as we got the empty slot so we will exit the loop
                }
            }
        }
        int count = 0;
        int profit = 0;
        for(int i =0 ; i<n ; i++)
        {
            if(visited[i] == true ) //where ever the job get visited index is true ther ans job number is also store in that index
            {
                count++;
                profit += arr[result[i]].profit;
            }
        }
        
        ans.push_back(count);
        ans.push_back(profit);
        return ans ;
    } 
};



// Greedy approach : select the jobs in dec order of profit and execute it if there is a free slot

// ----------------- My approach - O(n^2) approach -----------------------
#include<bits/stdc++.h>
using namespace std;

struct Job {
    int profit;
    int dead;
    int id;
};


bool sortFun (Job a, Job b) {
    return a.profit>b.profit;
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    unordered_map<int, bool> check;
    sort(arr, arr+n, sortFun);
    int count=0, ans=0;
    for(int i=0; i<n; i++) {
        int j=arr[i].dead - 1;
        while(j>=0) {
            if(!check[j]) {
                check[j]=true;
                count++;
                ans+=arr[i].profit;
                break;
            }
            j--;
        }
    }
    return make_pair(count, ans);
}

// ------------------------ O(n) approach on gfg------------------
//* https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/
// The idea is to create all the adjacent booked time slots into one set.
