// accepted in interviewbit

string res;

void solved(string &s , int k ,int n)
{
    
    if(k==0)
    {
        if(res<=s)
            {
                res = s;
            }
        return;
    }
    for(int i = 0 ; i<n-1 ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            swap(s[i],s[j]);
            solved(s,k-1,n); // we should do k-1 rather than k--
            swap(s[i],s[j]);
        }
    }
    return;
}


string Solution::solve(string A, int B) {
    res = A;
    int n = A.length();
    solved(A,B,n);
    return res;
}


// accepted in geeks for geeks 
class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    
    void findMax(string str, int k, int i, string &ans){
        if(i == str.size() - 1 || k == 0){
            if(ans < str){
                ans = str;
            }
            return; 
        }
        for(int j = i + 1; j < str.size(); j++){
            if(str[j] > str[i]){
                swap(str[i], str[j]);
                findMax(str, k - 1, i + 1, ans);
                swap(str[i], str[j]);
            }
        }
        findMax(str, k, i + 1, ans);
    }
    string findMaximumNum(string str, int k)
    {  
        string ans = str;
        findMax(str, k, 0, ans);
        return ans;
    }
};
