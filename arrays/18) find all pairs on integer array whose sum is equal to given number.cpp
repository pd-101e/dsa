// Approach 1:  Hash
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>mp;
        int ans = 0 ;
        for(int i =0 ; i<n ; i++)
        {
            if(mp.count( k -arr[i] ) != 0)
            {
                ans += mp[k-arr[i]];
            }
             mp[arr[i]]++;
        }
        return ans;
    }
};

// Approach 2: Sort the array. Using two pointer approach count the possible pairs. (TC-O(nlogn) SC-O(1))
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        sort(arr, arr+n);
        
        int l=0, r=n-1, result=0;
        while(l<r) {
            if(arr[l]+arr[r] == k) {
                int temp = r;
                while(temp>l && arr[temp] == arr[r]) {
                    temp--;result++;
                }
                l++;
            } else if (arr[l]+arr[r] < k) {
                l++;
            } else {
                r--;
            }
        }
        return result;
    }
};
