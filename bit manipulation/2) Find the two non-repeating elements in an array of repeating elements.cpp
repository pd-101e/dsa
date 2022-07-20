// method with extra space
class Soluiton{

public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int>ans;
        set<int>s;
        
        for(auto x : nums)
        {
            if(s.count(x)){
                s.erase(x);
            }
            else {
                s.insert(x);
            }
        }
        
        for(auto x:s)
        {
            ans.push_back(x);
        }
        
        return ans;
        
    }
};

//method 2 bit manipulation
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int>ans(2);
        int n = nums.size();
        int xors = 0;
        for(int i = 0 ; i<n ; i++)
        {
            xors = xors ^ nums[i];
        }
        
        int rightsetbit = xors & ~(xors - 1);
        
        int x = 0 , y = 0 ;
        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] & rightsetbit)
            {
                x = x ^ nums[i];
            }
            else {
                y = y ^ nums[i];
            }
        }
        ans[0] = x;
        ans[1] = y;
        if(x > y)
        {
            swap(ans[0] , ans[1]);
        }
        return ans;
    }
};
