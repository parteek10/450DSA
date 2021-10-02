class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(!head)
            return nullptr;
        node* p=nullptr;
        node* q=head;
        node* r=head->next;
        node* h=nullptr;
        node* t=nullptr;
        node* pvh=nullptr;
        node* pvt=nullptr;
        node* newHead=nullptr;
        while(q)
        {
            int count=k;
            while(q && count--)
            {
                if(p==nullptr)
                    h=q;
                q->next=p;
                p=q;
                q=r;
                if(r)
                    r=r->next;
                t=p;
            }
            if(newHead==nullptr)
                newHead=t;
            if(pvh)
                pvh->next=t;
            pvh=h;
            pvt=t;
            p=nullptr;
        }
        return newHead;
    }
};