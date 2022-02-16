/*
For each character, store the sequence which should be obtained at its respective position in an array, 
i.e. for Z, store 9999. For Y, store 999. For K, store 55 and so on.
For each character, subtract ASCII value of ‘A’ and obtain the position in the array pointed 
by that character and add the sequence stored in that array to a string.
If the character is a space, store 0
Print the overall sequence.
*/

// refer https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/ for code

// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;

// Function which computes the sequence
string printSequence(string arr[],
					string input)
{
	string output = "";

	// length of input string
	int n = input.length();
	for (int i=0; i<n; i++)
	{
		// Checking for space
		if (input[i] == ' ')
			output = output + "0";

		else
		{
			// Calculating index for each
			// character
			int position = input[i]-'A';
			output = output + arr[position];
		}
	}

	// Output sequence
	return output;
}

// Driver function
int main()
{
	// storing the sequence in array
	string str[] = {"2","22","222",
					"3","33","333",
					"4","44","444",
					"5","55","555",
					"6","66","666",
					"7","77","777","7777",
					"8","88","888",
					"9","99","999","9999"
				};

	string input = "GEEKSFORGEEKS";
	cout << printSequence(str, input);
	return 0;
}

