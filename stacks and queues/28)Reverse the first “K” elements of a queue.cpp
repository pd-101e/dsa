
// approach 1 iterative one 
queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    
   queue<int>ans;
   stack<int>s;
   while(k-->0)
   {
       int x = q.front();
       s.push(x);
       q.pop();
       
   }
   while(!s.empty())
   {int x=s.top();
       ans.push(x);
       s.pop();
   }
   
   while(!q.empty())
   {int x = q.front();
       ans.push(x);
       q.pop();
   }
   
   
   return ans;
   
   
}

// interative approach 2
// My iterative approach using stack
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> temp;
    for (int i=0; i<k; i++) {
        temp.push(q.front());
        q.pop();
        
    }
    queue<int> res;
    for (int i=0; i<k; i++) {
        res.push(temp.top());
        temp.pop();
    }
    
    while (!q.empty()) {
        res.push(q.front());
        q.pop();
    }
    return res;
}
