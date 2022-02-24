class Solution{
{
    /*
    The frequency of all the elements in A must be same as the frequency of all the elements in B. If it isn't return -1.
    To find minimum number of operations, start matching from last characters of both strings.
If last characters match, then our task reduces to n-1 characters.
If last characters don’t match, then find the position of B’s mismatching character in A.
The difference between two positions indicates that these many characters of A must be moved before current character of A.

    
    */
    public:
    int transform (string A, string B)
   {
       if (A.length() != B.length())
       {
           return -1;
       }
       int sum = 0 , sum1 = 0;
       int i = A.length() - 1 , j = B.length() - 1;
       int ct = 0;
       unordered_map <char, int> m;
        int n = A.length ();
    
        for (int i = 0; i < n; i++)
            m[A[i]]++;
    
        for (int i = 0; i < n; i++)
            if (m[B[i]])
                m[B[i]]--;
    
        for (auto i : m)
        {
            if (i.second != 0)
            {
                return -1;
            }
        }
    
       i = A.length() - 1;
       j = B.length() - 1;
       
       while (i >= 0 && j >= 0)
       {
           if (A[i] == B[j])
           {
               i--;
               j--;
           }
           else
           {
               ct++;
               i--;
           }
       }
       return ct;
   }
};
