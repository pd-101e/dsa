/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    int res = 0;
    int hi = 0;
    void height(int sum , int h ,Node* root)
    {
        if(root == NULL)
        {
            if(hi < h)
            {
                res = sum;
                hi = h;
            }
            else if(hi == h){
                if(res < sum)
                {
                    res = sum;
                }
            }
            return;
        }
        
        height(sum + root -> data , h+1,root->left);
         height(sum + root -> data , h+1,root->right);
         return;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        height(0 , 0 ,root);
        return res;
        
    }
};
