class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* merge(Node * head1 , Node* head2)
    {
        if(head1 == NULL || head2 == NULL)
        {
            if(head1)
            {
                return head1;
            }
            if(head2)
            {
                return head2;
            }
            return NULL;
        }
        
        if(head1->data <= head2->data)
        {
            head1 -> next = merge(head1->next,head2);
            return head1;
        }
        else if(head1->data > head2->data)
        {
            head2 -> next = merge(head1,head2->next);
            return head2;
        }
        
        
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        Node* slow  = head ;
        Node* fast = head;
        Node* prev =NULL;
        while( fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast -> next ->next;
            
        }
        if(fast)
        {
            prev = slow;
            slow = slow -> next;
        }
        prev -> next = NULL;
        Node* a = mergeSort(head);
        Node* b = mergeSort(slow);
        return merge(a,b);
        
        
        
    }
};
