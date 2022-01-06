
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

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(int &res, Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = solve(res,root->left);
        int rh = solve(res,root->right);
        
        res = max(lh+rh+1,res);
        return max(lh,rh) + 1;
        
    }
  
    int diameter(Node* root) {
        // Your code here
        int res = 0;
        solve(res,root);
        return res;
        
    }
};
