/*struct Node
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


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int>ans;
      queue<Node*>q;
      if(node == NULL)return ans ;
      q.push(node);
      
      while(!q.empty())
      {
          int size = q.size();
          for(int i = 0 ; i<size ; i++)
          {
              auto curr = q.front();
              q.pop();
              ans.push_back(curr -> data);
              if(curr->left != NULL)
              {
                  q.push(curr->left);
                  
              }
              if(curr->right)
              {
                  q.push(curr->right);
              }
              
          }
      }
      return ans;
      
      
    }
};
