vector <int> zigZagTraversal(Node* root)
{
	// Code here
	queue<Node*>q;
	vector<int>v;
	q.push(root);
	stack<int>s;
	
	bool reverse  = false;
	
	while(!q.empty())
	{
	    int count = q.size();
	    for(int i = 0 ; i<count; i++)
	    {
	        Node* curr = q.front();
	        q.pop();
	        if(reverse)
	        {
	            s.push(curr->data);
	        }
	        else
	        {
	            v.push_back(curr->data);
	            
	        }
	        
	        if(curr->left)
	        {
	            q.push(curr->left);
	        }
	        if(curr->right)
	        {
	            q.push(curr->right);
	        }
	        
	    }
	    
	    if(reverse)
	    {
	        while(!s.empty())
	        {
	            v.push_back(s.top());
	            s.pop();
	        }
	    }
	    reverse=!reverse;
	}
	return v;
	
}
