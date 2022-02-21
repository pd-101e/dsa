class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<= high)
        {
            int mid = low + (high - low )/2;
            if(arr[mid]==x)
            {
                return mid;
            }
            else if(arr[low]<=arr[mid])
            {
                if(x>=arr[low] and x<arr[mid])
                {
                    high = mid -1;
                }
                else low = mid+1;
            }
            else {
                if(x<=arr[high] and x>arr[mid])
                {
                    low = mid +1;
                }
                else high = mid -1;
            }
        }
        return -1;
    }
};


// Approach 1: Find the pivot that is the index with minimum element. Then binary search on one side of pivot according to target
int search(vector<int>& nums, int target) {
        
    int low=0, high=nums.size()-1, pivot=0;
    while(low<high) {
        int mid=(low+high)/2;
        
        if (nums[mid]>nums[high]) {
            low = mid+1;
        } else {
            high = mid;
        }
    }
    
    pivot=low;
    if(target>=nums[pivot] && target<=nums[nums.size()-1]) {
        low=pivot;
        high=nums.size()-1;
    } else {
        low=0;
        high=pivot;
    }
    
    while(low<=high) {
        int mid=(low+high)/2;
        
        if(nums[mid]==target) return mid;
        else if (nums[mid]>target) high=mid-1;
        else low = mid+1;
    }
    return -1;
}

// Approach 2: Solution with one binary search
public int search(int[] A, int target) {
    int lo = 0;
    int hi = A.length - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] == target) return mid;
        
        if (A[lo] <= A[mid]) {
            if (target >= A[lo] && target < A[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (target > A[mid] && target <= A[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return A[lo] == target ? lo : -1;
}
