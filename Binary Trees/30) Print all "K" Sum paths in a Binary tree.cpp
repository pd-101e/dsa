
/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
  int count = 0;
  vector<int>path;
  
  void solve(Node* root , int k)
  {
      if(root == NULL)
      return;
      path.push_back(root->data);
      solve(root->left,k);
      solve(root->right,k);
      int sum = 0 ;
      for(int i = path.size() - 1; i>=0 ; i--)
      {
          sum += path[i];
          if(sum == k)
          {
              count++;
            //   for(int m = i ; m<path.size() - 1; m++)
            //   {
            //       cout<<path[m]<<"";
            //   }
            //   cout<<endl;
          }
      }
      path.pop_back();
      
      return;
  }
  
    int sumK(Node *root,int k)
    {
        // code here 
        
        solve(root,k);
        
        return count;
        
    }
};
