// recursive code

Node *removeDuplicates(Node *head)
{
 // your code goes here
    if(head == NULL or head->next == NULL)
    {
        return head;
    }
     
     Node *resthand = removeDuplicates(head->next);
     head ->next = resthand; // importan step while doing recur always remember to 
     // ling the head with recur part
     if(resthand==NULL)
     {
         return head;
     }
     if(head -> data == resthand->data)
     {
         Node *temp = head;
         head = head->next;
         delete temp;
     }
     return head;
 
 
 
}

// iterative code
Node *removeDuplicates(Node *head)
{
 // your code goes here
   Node* curr =head;
    if(head==NULL||curr->next==NULL)
    {
        return head;
    }
    
    else{
        
        while(curr->next!=NULL&&curr!=NULL)
        {
            if(curr->next->data==curr->data)
            {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                
            }
            else curr= curr->next;
        }
        return head;
    }
}
