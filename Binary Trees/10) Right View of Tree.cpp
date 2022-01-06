// recursive

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    void rightview(Node* root ,vector<int> &ans, int level , int &maxlevel)
    {
     if(root==NULL)return ;
    
    if(maxlevel<level)
    {
        ans.push_back(root->data);
        maxlevel = level;
    }
    rightview(root->right,ans,level+1,maxlevel); // jus interchange right and left
    rightview(root->left,ans,level+1,maxlevel);// call right first for right view and for left view call left first
    return;
    
    
    }
    
    
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans ;
   if(root==NULL)return ans;
   int maxlevel=0;
   rightview(root,ans,1,maxlevel);
   return ans;
    }

    
};







//iterative


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       
        vector<int>ans;
   
   if(root == NULL) // be carefull of base condn
   return ans;
   
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       int size = q.size();
       for(int i = 0 ; i<size ; i++)
       {
           auto curr = q.front();
           q.pop();
           if(i==size-1)
           {
               ans.push_back(curr->data);
           }
           if(curr->left)
           {
                q.push(curr->left);   
           }
           if(curr ->right)
           {
               q.push(curr -> right);
           }
           
           
       }
       
   }
   
   
   return ans;
       
    }
};
