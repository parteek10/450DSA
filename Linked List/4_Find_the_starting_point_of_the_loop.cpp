//https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }

};

//to insert a value in ll at tail
void insertAtTail(node* &head, int val){
    node* n=new node(val);

    if (head==NULL)
    {
        head=n;
        return;
    }
    
    node* temp =head;
    while (temp -> next != NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}

//to insert a value in ll at head
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

//to display all elements
void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void make_cycle(node* &head,int pos){
    int count=0;
    node* temp=head;
    node* cyc;
    while (temp->next != NULL)
    {
        count++;
        if (count==pos)
        {
            cyc=temp;
        }
        
        temp=temp->next;
    }
    temp->next=cyc;
}

void find_starting_point(node* head)
    {
        node* fast=head;
        node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
              slow=head;
                while(slow!=fast){
                  slow=slow->head;
                  fast=fast->head;
                  
                }
              //here we get the starting point
              cout<<"loop start at point slow->data\n";
              return;
            }
        }
  cout<<ït doesn't have any loop\n";
    }

int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtHead(head,9);
    insertAtHead(head,5);;
    insertAtTail(head,7);
    
    int pos;
    cin>>pos;
    make_cycle(head,pos);
    find_starting_point(head);
 return 0;
}
