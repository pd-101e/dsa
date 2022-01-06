/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    // pehele jo ataa hai wo karte hai simple levelorder
    
    vector<int>ans;
    queue<Node*>q;
    q.push(root);
    stack<int>ansstack;
    while(!q.empty())
    {
        int size = q.size();
        stack<int>temp;
        
        for(int i = 0 ; i<size ; i++)
        {
            auto curr = q.front();
            q.pop();
            temp.push(curr->data);
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
            
        }
        while(!temp.empty())
        {
            ansstack.push(temp.top());
            temp.pop();
        }
        
        
    }
    
    while(!ansstack.empty())
    {
        ans.push_back(ansstack.top());
        ansstack.pop();
    }
    return ans;
    
    
}
