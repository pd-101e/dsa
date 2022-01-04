class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int>s;
     
     Node* curr = head;
     Node* prev = NULL;
     
     while(curr!=NULL)
     {
         if(s.count(curr->data) != 0)
         {
             prev->next = curr->next;
             delete curr;
             curr = prev->next;
         }
         else 
         {
             s.insert(curr->data);
             prev = curr;
             curr = curr->next;
         }
     }
     
     return head;
     
     
     
    }
};
