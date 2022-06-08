class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool mycmp( pair<int,int> &a , pair<int,int> &b)
    {
        return a.second < b.second;
    }
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        if(n==1)
        {
            return 1;
        }
        
        pair<int,int> arr[n];
        for(int i = 0 ; i<n ; i++)
        {
            
            arr[i] = make_pair(start[i],end[i]);
        }
        sort(arr,arr+n, mycmp);
        int count = 1;
        int prev = 0;
        for(int curr = 1; curr<n ; curr++)
        {
            if(arr[prev].second < arr[curr].first)
            {
                prev = curr;
                count++;
            }
        }
        
        return count;
        
    }
};
