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

