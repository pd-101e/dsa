// Approach 1: sort the array and remove repetitions then find the longest subarray in one traversal (TC-O(nlogn) SC-O(1))

// Approach 2: insert all the element in a set. Iterate through all the element if it is a start of a subsequence find its
// length else do nothing. return the maximum length. (TC-O(n) SC-O(n))

// Approach 3: (similar to approach 2) This is how i implemented
// mark the occurance of all elements in a map and then check for longest sequence of integers that exist in array by iterating
// from 1 to maximum element. (TC-O(nlogn) SC-O(1))
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_map<int, bool> m;
    int maxval=-1;
    for(int i=0; i<n; i++) {
        m[arr[i]] = true;
        maxval = max(maxval, arr[i]);
    }
    int count=0, maxcount=0;
    for(int i=0; i<=maxval; i++) {
        if(m[i]) {
            count++;
        } else {
            count=0;
        }
        maxcount= max(maxcount, count);
    }
    return maxcount;
}

/*************************************************/

class Solution{
 public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      
      unordered_set<int>s(arr,arr+n);
      // 2n lookups;
      int res = 0;
      for(auto x:s)
      {
          int count = 0 ;
          if(s.count(x-1) == 0)
          {
                while(s.count(x + count) == 1)
                {
                    count++;
                    
                }
                res = max(res,count);
          }
          
      }
      
      return res;
    }
};

/// 
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      //we will do 2n look ups O(N) time
      int res = 0 ;
      unordered_set<int>s(arr,arr+n);
      
      for(auto x:s)
      {
          if(s.find(x-1)==s.end())
          {
              int curr = 1;
              while(s.find(curr+x)!=s.end())
              {
                  curr++;
              }
              res = max(res,curr);
          }
      }
     return res;
      
    }
};
