// Sort the array
// Fix first two elements then find the rest two by two pointer algo
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int l,r;
        vector<vector<int>>ans;
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0 ;i<n-3 ; i++ )
        {
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            for(int j=i+1;j<n-2;j++)
            {if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                 l=j+1, r=n-1;
               while(l<r)
               {
                   int old_l = l;
                int old_r = r;
                    if(k==arr[i]+arr[j]+arr[l]+arr[r])
                {
                    ans.push_back({arr[i],arr[j],arr[l],arr[r]});
                    while (l < r && arr[l] == arr[old_l]) l++;
                    while (l < r && arr[r] == arr[old_r]) r--;
                }
                else if(k>arr[i]+arr[j]+arr[l]+arr[r])
                {
                    l++;
                }
                else {
                    r--;
                }
               }
                
            }
        }
        return ans;
    }
};
