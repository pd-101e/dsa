class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    int n = s.length();
		    int range = pow(2,n) - 1;
		    for(int mask = 1 ; mask <=range ; mask++)
		    {
		        string temp = "";
		        for(int j = 0; j<n ; j++)
		        {
		            
		            if((mask & (1<<j)) != 0)
		            {
		                temp = temp + s[j];
		            }
		        }
		        ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
