// Approach 1: Niave approach- In two nested loops, check the sum of all possible subarrays. (TC-O(n^2))
//https://leetcode.com/problems/minimum-size-subarray-sum/submissions/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX ;
        int n = nums.size();
        int i = 0 , j = 0 ;
        int sum = 0;
        while(j<n)
        {
             sum = sum + nums[j];
            if(sum < target)
            {
               
                j++;
            }
            else if(sum >= target)
            {
                
                res = min(res,j-i+1);
                while(sum >= target)
                {
                 res = min(res,j-i+1);
                    sum = sum - nums[i];
                    i++;
                }
                j++;
            }
            
        }
        
        if(res == INT_MAX)
        {
            return 0;
        }
        return res;
    }
};



///////

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX ;
        int n = nums.size();
        int i = 0 , j = 0 ;
        int sum = 0;
        while(j<n)
        {
             sum = sum + nums[j];
            if(sum < target)
            {
               
                j++;
            }
            else if(sum >= target)
            {
                
                res = min(res,j-i+1);
                while(sum >= target and i<=j)
                {
                 res = min(res,j-i+1);
                    sum = sum - nums[i];
                    i++;
                }
                j++;
            }
            
        }
        
        if(res == INT_MAX)
        {
            return 0;
        }
        return res;
    }
};



/// copied
// Approach 1: Niave approach- In two nested loops, check the sum of all possible subarrays. (TC-O(n^2))

// Approach 2: two pointer approach- refer code below. (TC-O(n))
int sb(int arr[], int n, int x)
{
    int sum=0, i=0, j=-1, minsubarray=n+1;
    while(1) {
        if(sum > x) {
            if(j-i+1 < minsubarray) {
                minsubarray = j-i+1;
            }
            sum-=arr[i];
            i++;
        } else {
            if(j==n-1) break;
            j++;
            sum+=arr[j];
        }
    }
    return minsubarray;
}
