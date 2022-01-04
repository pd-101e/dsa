// recursive
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        Node* resthead = reverseList(head->next);
        Node* resttail = head->next;
        resttail->next = head;
        head ->next = NULL;
        return resthead;
        
    }
    
};
    
// iterative
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        // if(head == NULL or head->next == NULL)
        // {
        //     return head;
        // }
        
        Node *prev = NULL;
        Node * curr = head;
       
        while(curr != NULL)
        {
             Node *next = curr->next; // remember
         curr -> next = prev;
         prev = curr;
         curr = next;
         
        }
        return prev;
    }
    
};
    
