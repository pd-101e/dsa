struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
 public:
   
   unordered_set<int> a;
   void height(Node * root,int h){
       if(!root)
       return ;
       if(!root->left && !root->right)
       a.insert(h);
       height(root->left,1+h);
       height(root->right,1+h);
       
   }
   bool check(Node *root)
   {
       
       height(root,0);
       if(a.size()==1)
       return true;
       else
       return false;
   }
};
