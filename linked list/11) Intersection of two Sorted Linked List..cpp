Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node * head3 = NULL;
    Node * tail = NULL;
    Node * curr1 = head1;
    Node * curr2 = head2;
    
    
    while((curr1!=NULL)&&(curr2!=NULL))
    {
        if(curr1->data < curr2->data)
        {
            curr1 = curr1->next;
        }
        else if(curr1->data > curr2->data)
        {
            curr2 = curr2 -> next;
            
        }
        else {
            
            
            Node* temp = new Node(curr1->data);
            curr1 = curr1->next;
            curr2 = curr2 -> next;
            if(head3==NULL)
            {
                tail=head3=temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
            
            
        }
        
    }
    return head3;
    
    
}
