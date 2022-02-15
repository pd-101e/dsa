/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

// Simplified code given on gfg : https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
void splitList(Node *head, Node **head1_ref, Node **head2_ref) { 
    Node *slow_ptr = head; 
    Node *fast_ptr = head; 
      
    if(head == NULL) 
        return; 
      
    /* If there are odd nodes in the circular list then 
       fast_ptr->next becomes head and for even nodes 
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head && fast_ptr->next->next != head) { 
        fast_ptr = fast_ptr->next->next; 
        slow_ptr = slow_ptr->next; 
    } 
      
    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head) 
        fast_ptr = fast_ptr->next; 
          
    /* Set the head pointer of first half */
    *head1_ref = head; 
          
    /* Set the head pointer of second half */
    if(head->next != head) 
        *head2_ref = slow_ptr->next; 
          
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next; 
          
    /* Make first half circular */
    slow_ptr->next = head; 
} 
