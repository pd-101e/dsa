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
