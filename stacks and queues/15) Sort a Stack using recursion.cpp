void insert(int x , stack<int>&s) // always remember to pass stack by refernce as it ias an function ccall so new memory will be allocated 
{
    if(s.empty() || s.top() <= x)
    {
        s.push(x);
        return ;
    }
    
    int temp = s.top();
    s.pop();
    insert(x,s);
    s.push(temp);
    return ;
    
    
}
void SortedStack :: sort()
{
   //Your code here
   if(s.size()==0 || s.size()==1)
   {
       return ;
   }
   int temp = s.top();
   s.pop();
   sort();
   insert(temp , s);
   return ;
}
