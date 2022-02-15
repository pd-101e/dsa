// approach 1 hashing
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node * >s;
    for(Node* curr = head1 ; curr!=NULL ; curr = curr->next)
    {
        s.insert(curr);
    }
     for(Node* curr = head2 ; curr!=NULL ; curr = curr->next)
    {
        if(s.count(curr)!=0)
        {
            return curr->data;
        }
    }
    return -1;
  
}

// approach 2 by algo
//Function to find intersection point in Y shaped Linked Lists.
int getcount(Node* head)
{
    Node* curr =head;
    int count=0;
    while(curr)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
int getintersection(int n , Node* head1 , Node* head2)
{
    
    Node* curr1= head1;
    Node* curr2= head2;
    for(int i = 0; i<n ; i++)
    {
        if(curr1==NULL)
        {
            return -1;
        }
        curr1=curr1->next;
    }
    while(curr1!=NULL&&curr2!=NULL)
    {
        if(curr1==curr2)            // !! beacare fill about this loop remmenber it 
         return curr1->data;
        curr1=curr1->next;
        curr2 = curr2->next;
    }
   
    return -1;
    
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int c1 = getcount(head1);
    int c2 = getcount(head2);
    int d;
    if(c1>c2)
    {
         d = c1-c2;
        return getintersection(d,head1,head2);
    }
    else
    {d = c2-c1;
    return getintersection(d,head2,head1);}
    
}
