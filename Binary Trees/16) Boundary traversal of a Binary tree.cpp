struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    
    void left(Node* root , vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }
        if(root -> left)
        {
            ans.push_back(root->data);
            left(root->left,ans);
        }
        else if (root->right)
        {
            ans.push_back(root->data);
            left(root -> right , ans);
        }
        
        return;
    }
    
    void leaf(Node* root , vector<int>&ans)
    {
        if(root == NULL)
        return ;
        
        leaf(root -> left , ans);
        if(root->left == NULL and root -> right == NULL)
        {
            ans.push_back(root -> data);
        }
        leaf(root ->right , ans);
        return;
    }
    
    void right(Node* root , vector<int>&ans)
    {
        if(root == NULL)
        {
            return ;
        }
        
        if(root -> right)
        {
            right(root -> right ,ans);
            ans.push_back(root -> data);
        }
        else if(root -> left)
        {
            right(root->left,ans);
            ans.push_back(root -> data);
        }
        return;
        
    }
    

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        
        if(root == NULL)
        return ans;
        
        ans.push_back(root -> data);
        if(root -> left == NULL and root -> right == NULL)
        {
            return ans ;
        }
        left(root -> left , ans);
        leaf(root , ans);
        right(root-> right , ans );
        
        return ans ;
        
        
    }
};
