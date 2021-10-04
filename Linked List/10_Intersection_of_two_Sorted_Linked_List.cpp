//https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

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

node* findIntersection(node* head1, node* head2)
{
  //create new linked list to store common values
    node* inter=new node(-1);
    node* head=inter;
    while(head1!=NULL && head2!=NULL){
        if(head1->data==head2->data){
            head->next=head1;
            head=head->next;
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data<head2->data)
            head1=head1->next;
        else
            head2=head2->next;
    }
    if(head->next!=NULL)
    head->next=NULL;
    
    return inter->next;
}

int main(){
    node* head1=NULL;
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtTail(head,11);
    insertAtTail(head,15);
  
    node* head2=NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,9);
    insertAtTail(head,11);
    insertAtTail(head,15);
    insertAtTail(head,20);
  
  display(findIntersection(head1,head2));
 return 0;
}
