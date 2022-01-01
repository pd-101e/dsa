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
// two pointer O(N) approach
/*
Algorithm : 


Create two indices i and j, where i = 0 and j = n-1
Run a loop until i is less than j.
Check if i knows j, then i can't be a celebrity. so increment i, i.e. i++
Else j cannot be a celebrity, so decrement j, i.e. j--
Assign i as the celebrity candidate
Now at last check that whether the candidate is actually a celebrity by re-running a loop from 0 to n-1  and constantly checking that if the candidate knows a person or if there is a candidate who does not know the candidate, then we should return -1. else at the end of the loop, we can be sure that the candidate is actually a celebrity.
*/
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
     
     int i = 0 ; int j = n-1 ;
     while(i<j)
     {
         if(M[j][i] == 1)
         {
             j--;
         }
         else 
         i++;
         
     }
     
     int candidate = i ;
     for(i = 0 ; i<n ; i++)
     {
         if(i!=candidate)
         {
             if(M[i][candidate] == 0 || M[candidate][i] == 1)
             {
                 return -1;
             }
         }
     }
     return candidate;
        
    }
};





// O(N) stack approach 
/*
Algorithm: 


Create a stack and push all the id's in the stack.
Run a loop while there are more than 1 element in the stack.
Pop top two element from the stack (represent them as A and B)
If A knows B, then A can't be a celebrity and push B in stack. Else if A doesn't know B, then B can't be a celebrity push A in stack.
Assign the remaining element in the stack as the celebrity.
Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
*/
bool knows(int a, int b)
{
    return MATRIX[a][b];
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    // Handle trivial 
    // case of size = 2
    stack<int> s;

    // Celebrity
    int C; 

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2
 

    // Find a potential celebrity
    while (s.size() > 1)
    {   int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
          s.push(B);
        }
        else
        {
          s.push(A);
        }
    }
    // If there are only two people 
    // and there is no
    // potential candicate
    if(s.empty())
        return -1;
  
  
    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't 
        // know 'C' or 'C' doesn't 
        // know any person, return -1
        if ( (i != C) &&
                (knows(C, i) || 
                 !knows(i, C)) )
            return -1;
    }

    return C;
}

