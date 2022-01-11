Node* reverse(Node* head)
    {
        
        Node* curr = head;
        Node* prev =NULL;
        
        while(curr!=NULL)
        {
            Node*next = curr->next;
            curr->next=prev;
            prev = curr;
            curr= next;
            
        }
        return prev;// alway remember that yiur prev is your. head
        
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        Node * sum=NULL;
        int carry = 0 ;
    while(first!=NULL||second!=NULL||carry!=0)//using loop till both of first , second  ansd carry get exhausted
    {
        int newval = carry;
        
        if(first) newval+= first->data;
        if(second) newval+= second->data;
        
        carry = newval/10;
        newval = newval%10;
        
        Node* newNode = new Node(newval);
        newNode -> next = sum ;
        sum= newNode;
        if(first) first = first->next;
        if(second) second = second -> next;
        
        
        
    }
    return sum;
    
    
    
    
    }
};
