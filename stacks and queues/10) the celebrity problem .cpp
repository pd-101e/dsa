// O(n^2) solution

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
     
     for(int i = 0 ; i<n ; i++)
     {
         int sum = 0 ;
         for(int j = 0 ; j<n ; j++)
         {
             sum += M[i][j];
         }
         if(sum == 0 )
         {
             for(int j = 0 ; j<n ; j++)
             {
                 sum += M[j][i];
             }
             if(sum == n-1 )
                  {
                      return i;
                 }
     
         }
         
     }
     return -1;
        
    }
};

// O(n^2) approach
int celebrity(vector<vector<int> >& M, int n) {
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            sum += M[i][j];
        }
        if (sum == 0) {
            for (int j=0; j<n; j++) {
                sum += M[j][i];
            }
            if (sum == n-1) return i;
            else return -1;
        }
    }
    return -1;
}
