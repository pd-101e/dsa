// approach 1 hashing
bool findPair(int arr[], int size, int n){
    //code
    
    unordered_set<int>s(arr,arr + size);
    if(n==0) // base condtn
    return false;
    for(int i = 0 ; i<size ; i++)
    {
        if(s.count(arr[i] + n) != 0)
        {
            return true;
        }
    }
    return false;
    
}

// 
// Approach 1: Use two loops and check every pair possible

// Approach 2: Sort the array, for each element, x,  binary search for x+diff

// Approach 3: Sort the array, use two pointer. Initialize the two pointer at index 0 and 1, then increment i and j
// according their difference

// Approach 4: Hash all the elements and check if x+diff exists or not in the map
