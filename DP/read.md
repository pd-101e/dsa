v = vector<vector<int>> (n+1, vector<int> (sum+1, -1));
vector<vector<long long int>> v;
   v = vector<vector<long long int>> (n+1, vector<long long int> (m+1, -1));

   
   
   9

if you want to initialize whole array to zero do this ,

int *p = new int[n]{0};
   
   
   int* arrayMain = new int[arraySize-1] ();
Note the () at the end - it's used to value-initialize the elements, so the array will have its elements set to 0.
