// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    bool flag = true;
    
    int solve(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int a = solve(root->left);
        int b = solve(root->right);
        if(root -> data != a+b and root -> left and root->right)
        {
            flag = false;
        }
        return a + b + root->data;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         solve(root);
         return flag;
    }
};
