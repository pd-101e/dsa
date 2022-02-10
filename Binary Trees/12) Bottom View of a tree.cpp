class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i<size ; i++)
            {
                auto p = q.front();
                int hr = p.second;
                auto curr = p.first;
                
                mp[hr] = curr->data;
                q.pop();
                
                
                if(curr->left != NULL)
                {
                    
                    q.push({curr->left,hr-1});
                }
                if(curr->right != NULL)
                {
                    q.push({curr->right,hr+1});
                }
                
            }
        }
        
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans ;
        
        
    }
};
