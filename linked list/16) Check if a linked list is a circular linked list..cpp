
/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   if(head == NULL or head ->next == NULL)
   {
       return false;
   }
   
   Node*curr = head;
   curr = curr -> next;
   while(curr)
   {
       if(curr == head)
       {
           return true;
       }
       curr = curr ->next;
   }
   
   return false;
   }
