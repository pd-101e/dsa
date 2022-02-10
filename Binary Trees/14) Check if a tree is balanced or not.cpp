class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* root)
    {
        if(root == NULL)
        return 0;
        
        int lh = height(root -> left);
        
        if(lh == -1)
        return -1;
        
        int rh = height(root -> right);
        if(rh == -1)
        return -1;
        
        
        int res = 1 + max(lh,rh);
        
        if(abs(lh-rh) > 1 )
        {
            return -1;
        }
        else return res;
        
        
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int ans = height(root);
        if(ans == -1)
        {
            return false;
        }
        else return true;
        
    }
};
