/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

unordered_map<string,int>mp;
vector<Node*>ans;
string solve(Node* root)
{
    if(root == NULL)
    {
        return "$";
    }

        // if(root -> left == NULL and root->right == NULL)
        // {
        //     s = s+ to_string(root -> data);
        //     return s;
        // }
        
        
        string s1  = solve(root -> left);
        string s2 = solve(root -> right);
        string s = "";
        s = s1 + to_string(root -> data) + s2;
        mp[s]++;
        if(mp[s]==2)
        {
            ans.push_back(root);
        }
        
        
        return s;
    
}


vector<Node*> printAllDups(Node* root)
{
    // Code here
      mp.clear();
   ans.clear();
    solve(root);
    return ans;
}
