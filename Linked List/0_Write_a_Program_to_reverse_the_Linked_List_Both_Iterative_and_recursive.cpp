// https://www.geeksforgeeks.org/reverse-a-linked-list/

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

//iterative approach to reverse a ll
node* reverse(node* &head){
    node* curr=head;
    node* pre=NULL;
    node* nxt;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=pre;

        pre=curr; 
        curr=nxt;

    }
    return pre;
}

//recursive approach to reverse a ll
node* reverse_recursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    node* newhead=reverse_recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newhead;
}

int main(){
    cout<<"hello"<<endl;
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    display(head);
    insertAtHead(head,9);
    insertAtHead(head,5);
    display(head);

    display(reverse(head));  //iterative approach

//     display(reverse_recursive(head));//recursive

 return 0;
}
