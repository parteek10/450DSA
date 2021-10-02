Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* dummy=new Node(0);
    Node* prev=dummy;
    Node* p=head1;
    Node* q=head2;
    while(p && q)
    {
        if(p->data>=q->data)
        {
            prev->next=q;
            prev=q;
            q=q->next;
            prev->next=nullptr;
        }
        else
        {
            prev->next=p;
            prev=p;
            p=p->next;
            prev->next=nullptr;
        }
    }
    p?prev->next=p:prev->next=q;
    prev=dummy->next;
    delete dummy;
    return prev;
}