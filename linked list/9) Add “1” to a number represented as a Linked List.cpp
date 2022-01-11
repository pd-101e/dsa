// My approach: 
class Solution
{
    public:
    
    bool util(Node *head) 
    {
        if (!head->next) {
            head->data = (head->data+1)%10;
            if (head->data) return false;
            else return true;
        }
        if (util(head->next)) {
            head->data = (head->data+1)%10;
            if (head->data) return false;
            else return true;
        }
        else return false;
    }
    Node* addOne (Node *head) {
        if (util (head)) {
            Node* newhead = new Node (1);
            newhead->next = head;
            head = newhead;
        }
        return head;
    }
};




//approach 2
/* 

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

class Solution
{
    public:
    
    Node* reverse(Node* head)
    {
        if(head == NULL or head -> next == NULL)
        {
            return head;
        }
        Node* resthead = reverse(head -> next);
        Node* resttail = head -> next;
        resttail -> next = head;
        head -> next = NULL;
        return resthead;
    }
    
    
   Node* addOne(Node *head) 
        { 
            head = reverse(head);           // reversing list to make addition easy
            
            Node* current = head;
            int carry = 1;
            
            while(carry)
            {
                current->data += 1;         // adding one to current node
                
                if(current->data < 10) return reverse(head);
                    // if no carry we can reverse back list and return it
                else current->data = 0;
                    // else we continue with taking carry forward
                
                if(current->next == NULL) break;
                    // if, end of list, we break from loop
                else current = current->next;
                    // else we move to next node
            }
            
            current->next = new Node(1);  // adding new node for the carried 1
            return reverse(head);
        }
};
