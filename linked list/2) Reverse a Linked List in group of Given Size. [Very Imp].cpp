// recursive
class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* curr = head;
        node* prev = NULL;
        node* next = NULL;
        int count = 1;
        while(curr != NULL and count <=k)
        {
            next  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next != NULL)
        {
            node* resthand = reverse(next,k);
            head->next = resthand;
        }
        return prev;
    }
};
