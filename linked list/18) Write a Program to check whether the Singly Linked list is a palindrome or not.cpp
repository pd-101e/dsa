
/*struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// approach 1 using stack
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        stack<int>st;
        for(Node* curr = head ; curr!=NULL ; curr = curr->next)
        {
            st.push(curr->data);
        }
        for(Node* curr = head ; curr!=NULL ; curr = curr->next)
        {
            if(st.top() != curr->data)
            {
                return false;
            }
            st.pop();
        }
        return true;
        
    }
};

 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL)
        {
            return true;
        }
        Node *slow = head, *fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast= fast->next->next;
            slow = slow->next;
            
        }
        Node* rev = reverse(slow->next);
        Node*curr=head;
        while(rev!=NULL)
        {
            if(rev->data!=curr->data)
           { slow->next = reverse(slow->next);
               return false;}
            rev = rev->next;
            curr = curr->next;
        }
        slow->next =reverse(slow->next);
        return true;
    }
    
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL)
        {
            Node* next = curr->next;
            curr->next=prev;
            prev= curr;
            curr = next;
        }
        return prev;
    }
};

//approach 2 iterative O(1) aux space

 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL)
        {
            return true;
        }
        Node *slow = head, *fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast= fast->next->next;
            slow = slow->next;
            
        }
        Node* rev = reverse(slow->next);
        Node*curr=head;
        while(rev!=NULL)
        {
            if(rev->data!=curr->data)
           { slow->next = reverse(slow->next);
               return false;}
            rev = rev->next;
            curr = curr->next;
        }
        slow->next =reverse(slow->next);
        return true;
    }
    
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL)
        {
            Node* next = curr->next;
            curr->next=prev;
            prev= curr;
            curr = next;
        }
        return prev;
    }
};



