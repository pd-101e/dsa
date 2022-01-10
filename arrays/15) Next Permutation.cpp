class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();

        for(int i = n-1 ; i>=1 ; i--)
        {
            if(nums[i-1]<nums[i])
            {
                idx = i;
                break;
            }
        }
        if(idx == -1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        int prev = idx;
        
        int boundary = nums[idx];
        for(int j = idx+1 ; j<n ; j++)
        {
            if(nums[j] > nums[idx-1] and nums[j]<=nums[prev] )
            {
                prev = j;
            }
        }
        
        swap(nums[idx-1],nums[prev]);
        reverse(nums.begin()+idx,nums.end());
        return ;
        
    }
};
