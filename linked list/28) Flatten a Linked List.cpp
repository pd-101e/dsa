/*  Function which returns the  root of 
    the flattened linked list. */
    
    Node * merge(Node* root1, Node* root2)
    {
        if(root1==NULL)
        return root2;
        if(root2==NULL)
        return root1;
        if(root1->data <= root2->data)
        {
            root1->bottom = merge(root1->bottom,root2);
            return root1;
        }
        else{ root2->bottom = merge(root1,root2->bottom);
        
            return root2;
        }
        
    }
    
    
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL||root->next == NULL)
   {
       return root;
   }
   Node *temp = flatten(root->next);
   return merge(root,temp);
   
   
}
