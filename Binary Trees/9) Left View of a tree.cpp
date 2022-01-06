// recursive ************************************
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void leftview(Node* root ,vector<int> &ans, int level , int &maxlevel)
{
     if(root==NULL)return ;
    
    if(maxlevel<level)
    {
        ans.push_back(root->data);
        maxlevel = level;
    }
    leftview(root->left,ans,level+1,maxlevel);
    leftview(root->right,ans,level+1,maxlevel);
    return;
    
    
}


vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans ;
   if(root==NULL)return ans;
   int maxlevel=0;
   leftview(root,ans,1,maxlevel);
   return ans;
}




//iterative **************************************

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   
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
           if(i==0)
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
