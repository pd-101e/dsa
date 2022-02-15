 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(!head||!head->next)
        return head;
        
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);
        
        Node *zero = zeroD ,*one = oneD , *two=twoD;
        
        for(Node* curr = head ; curr!=NULL; curr =curr->next)
        {
            int x =curr->data;
            
            if(x==0)
            {
                zero->next = curr;
                zero = zero->next;
               
            }
            else if(x==1)
            {
                one->next = curr;
                one = one->next;
                
            }
            else{
                two->next = curr;
                two = two->next;
                
                
            }
        }
        zero->next = oneD->next ? oneD->next : twoD->next ;
        one->next = twoD->next;
        two->next =NULL;
        head = zeroD->next;
        delete zeroD;
        delete oneD;
        delete twoD;
        return head;
        
        
    }
};

