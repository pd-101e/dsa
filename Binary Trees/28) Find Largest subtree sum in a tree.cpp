// Helper function to find largest
// subtree sum recursively.
int findLargestSubtreeSumUtil(Node* root, int& ans)
{
    // If current node is null then
    // return 0 to parent node.
    if (root == NULL)    
        return 0;
     
    // Subtree sum rooted at current node.
    int currSum = root->key +
      findLargestSubtreeSumUtil(root->left, ans)
      + findLargestSubtreeSumUtil(root->right, ans);
 
    // Update answer if current subtree
    // sum is greater than answer so far.
    ans = max(ans, currSum);
 
    // Return current subtree sum to
    // its parent node.
    return currSum;
}
