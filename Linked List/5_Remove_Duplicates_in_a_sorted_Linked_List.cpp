//https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

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

void removeDuplicates(node* head)
{
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
            continue;
        }
        temp=temp->next;
    }
    
}

int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtTail(head,12);
    insertAtTail(head,12);
    insertAtTail(head,12);
    insertAtTail(head,15);
    insertAtTail(head,20);
    display(head);
  
    removeDuplicates(head);
    display(head);
return 0;
}
