// detect loop
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // here we will use flou'd cycle detection
        // your code here
        //intitialize the slow and fast by head
        // move slow by 1 and fast by 2 , if those pointer meet there is a loop
        Node *fast = head;
        Node *slow = head;
        while(fast!=NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                return true;
            }
            
            
        }
        return false;
        
        
        
    }
};
