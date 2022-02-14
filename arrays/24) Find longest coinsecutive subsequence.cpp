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
