
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    // we will build the tree in preorder fashion
    int preindex = 0;
    Node* solve(int is , int ie , int in[] , int pre[] , int n)
    {
        if(is > ie)
        return NULL;
        
        Node* root = new Node(pre[preindex++]);
        int inndex ;
        for(int index = is ; index <= ie ; index++)
        {
            if(in[index] == root -> data)
            {
                  inndex = index;
                  break;
            }
        }
        root -> left = solve(is,inndex - 1 , in , pre , n);
        root -> right = solve(inndex + 1 , ie , in , pre , n);
        return root;
        
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return solve(0,n-1,in,pre,n);
    }
};
