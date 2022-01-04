class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* fast = head;
        Node* slow = head;
        
        while(fast!=NULL and fast->next != NULL and slow)
        {
            fast = fast->next->next;
            slow = slow ->next;
            if(fast == slow )
            {
                break;
            }
        
        }            
        if(fast!=slow)
        return;
        if(slow == head)
        {
            while(slow->next != head)
            {
                slow = slow -> next;
            }
            slow -> next = NULL;
            
        }
        else
        
        {slow = head;
        while(slow->next != fast->next)
        {
            slow = slow ->next;
            fast = fast->next;
        }
        
        fast ->next = NULL;}
        return ;
        
        
        
    }
};
