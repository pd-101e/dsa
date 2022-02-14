// Approach 1: Using two nested loops count the occurance of all elements and print those whose count is more than n/k. (TC-O(n^2))

// Approach 2: First sort, then count. (TC-O(nlogn))

// Approach 3: (a bit confusing refer - https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/)
/* 1) Create a temporary array of size (k-1) to store elements and their counts (The output elements are going to be among these k-1 elements). Following is structure of temporary array elements. 
struct eleCount {
    int element;
    int count;
}; 
struct eleCount temp[];         // This step takes O(k) time. 
2) Traverse through the input array and update temp[] (add/remove an element or increase/decrease count) for every traversed element. The array temp[] stores potential (k-1) candidates at every step. This step takes O(nk) time.
3) Iterate through final (k-1) potential candidates (stored in temp[]). or every element, check if it actually has count more than n/k. This step takes O(nk) time.
The main step is step 2, how to maintain (k-1) potential candidates at every point? The steps used in step 2 are like famous game: Tetris. We treat each number as a piece in Tetris, which falls down in our temporary array temp[]. Our task is to try to keep the same number stacked on the same column (count in temporary array is incremented).
*/

// Approach 4: Hash all the elements and then iterate through the hash map and print the elements with count more than n/k. (TC-O(n))




// C++ code to find elements whose
// frequency yis more than n/k
#include<bits/stdc++.h>
using namespace std;

void morethanNbyK(int arr[], int n, int k)
{
	int x = n / k;
	
	// unordered_map initialization
	unordered_map<int, int> freq;

	for(int i = 0; i < n; i++)
	{
		freq[arr[i]]++;
	}

	// Traversing the map
	for(auto i : freq)
	{
		
		// Checking if value of a key-value pair
		// is greater than x (where x=n/k)
		if (i.second > x)
		{
			
			// Print the key of whose value
			// is greater than x
			cout << i.first << endl;
		}
	}
}

// Driver Code
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 5,
				4, 2, 2, 3, 1, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	
	morethanNbyK(arr, n, k);

	return 0;
}

// This code is contributed by chayandas018

