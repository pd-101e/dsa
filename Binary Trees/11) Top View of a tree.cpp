/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>v;
        map<int,int >mp; // in sorted form
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto p = q.front();
            Node* curr = p.first;
            int hd = p.second;
            
            if(mp.find(hd)==mp.end())
            mp[hd] = curr->data;
            q.pop();
            if(curr->left!=NULL)
            {
                q.push({curr->left,hd-1});
            }
            if(curr->right!=NULL)
            {
                q.push({curr->right,hd+1});
            }
            
            
            
        }
        for(auto m:mp)
        {
            v.push_back(m.second);
        }
     return v;   
    }

};
