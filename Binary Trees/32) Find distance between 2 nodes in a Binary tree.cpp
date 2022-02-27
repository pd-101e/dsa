struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
   Node* lca(Node* root, int a, int b){
        if(root==NULL || root->data==a || root->data==b) return root;
        Node* l = lca(root->left,a,b);
        Node* r = lca(root->right,a,b);
        if(l && r) return root;
        if(l) return l;
       else  if(r) return r;
    }
    
    int dist(Node* root, int tar, int level){
        if(root==NULL) return INT_MAX;
        if(root->data==tar) return level;
        int a = dist(root->left,tar,level+1);
        int b = dist(root->right,tar,level+1);
        return min(a,b);
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* l = lca(root,a,b);
        return dist(l,a,0)+dist(l,b,0);
    }
};
