/* A binary tree node has data, pointer to left child
   and a pointer to right child /
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
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        
        if(root == NULL)
        {
            return ;
            
        }
        
        Node * temp = root->left;
        root->left = root->right;
        root ->right = temp;
        
        mirror(root -> left);
        mirror(root -> right);
        
        
        return ;
        
        
    }
};

// Approach 2: call the function with two root nodes and reccurse it for left of original and right of new tree and vice versa

class Solution {
public:
    void invertHelper(TreeNode* r1, TreeNode* m) {
        if(r1->right) {
            m->left = new TreeNode(r1->right->val);
            invertHelper(r1->right, m->left);
        }
        if(r1->left) {
            m->right = new TreeNode(r1->left->val);
            invertHelper(r1->left, m->right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* m = new TreeNode(root->val);
        invertHelper(root, m);
    }
};
