/*
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    
    unordered_map<string,int>mp;
    
    string solve(Node* root)
    {
        if(root == NULL)
        return "$";
        
        string s = "";
        if(root -> left == NULL and root->right == NULL)
        {
            s = s+ to_string(root -> data);
            return s;
        }
        
        s = s + to_string(root -> data);
        s = s + solve(root -> left);
        s = s + solve(root -> right);
        
        mp[s]++;
        return s;
        
        
    }
    
    int dupSub(Node *root) {
         // code here
         solve(root);
         for(auto x:mp)
         {
             if(x.second > 1)
             {
                 return 1;
             }
         }
         return 0;
         
    }
};
