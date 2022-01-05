
class Solution{

	public:
	
	void solve(vector<string>&ans , string &s, bool visited[] , string &temp )
	{
	    if(temp.length() == s.length())
	    {
	        ans.push_back(temp);
	        return;
	    }
	    for(int i = 0 ; i<s.length(); i++)
	    {
	        if(!visited[i])
	        {
	            visited[i] = true;
	            temp.push_back(s[i]);
	            solve(ans,s,visited,temp);
	            temp.pop_back();
	            visited[i] = false;
	        }
	    }
	    return;
	}
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    int n = S.length();
		    bool visited[n];
		    for(int i = 0 ; i<n ; i++)
		    {
		       visited[i] = false;
		    }
		    string temp ="";
		    solve(ans,S,visited,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// approach 2
vector<string> res;
void util (string S, int idx) {
    
    if (idx==S.size()) {
        res.push_back(S);
        return;
    }
    for (int i=idx; i<S.size(); i++) {
        swap(S[i], S[idx]);
        util (S, idx+1);
        swap(S[i], S[idx]);
    }
}
vector<string>find_permutation(string S)
{
    util (S, 0);
    sort(res.begin(), res.end());
    return res;
}

// If string contains duplicates : https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/
// did not understood the above link refer it in fresh mind

