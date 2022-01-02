// by recursion
void recur(queue<int> &ans)
{
    if(ans.empty() || ans.size() == 1)
    {
        return ;
    }
    int temp = ans.front();
    ans.pop();
    recur(ans);
    ans.push(temp);
    return ;
}

queue<int> rev(queue<int> q)
{
    // add code here.
    queue<int>ans = q ;
    recur(ans);
    return ans;
    }

// queue reversal using stack
queue<int> rev(queue<int> q)
{
    // add code here.
    queue<int>ans;
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        int k = s.top();
        s.pop();
        ans.push(k);
        
    }
    return ans;
    
    
}
