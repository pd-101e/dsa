/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors; // adj of this graph traverse it like node->neighbour
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


// O(V+E)
class Solution {
public:
    
    void dfs(Node* node , Node* clone, vector<Node*>&vis)
    {
        vis[clone->val] = clone;
        
        for(auto x:node->neighbors)
        {
            if(vis[x->val]== NULL)
            {
                Node* newnode = new Node(x->val);
                (clone->neighbors).push_back(newnode);
                dfs(x,newnode,vis);
            }
            else
            {
                (clone->neighbors).push_back(vis[x->val]);
            }
        }
        return;
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
        {
            return NULL;    
        }
        
        Node* clone = new Node(node -> val);
        vector<Node*>vis(1000,NULL);
        
        dfs(node,clone,vis);
        return clone;
        
        
        
        
    }
};
