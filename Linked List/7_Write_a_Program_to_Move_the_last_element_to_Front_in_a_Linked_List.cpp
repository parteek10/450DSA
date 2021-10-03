// https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

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

node* move_last_element_to_front(node* head)
{
  if(head==NULL || head->next==NULL){
    return head;
  }
    node* temp=head;
    while(temp->next->next!=NULL){
      temp=temp->next;
    }
  temp->next->next=head;
  head=temp->next;
  temp->next=NULL;
  
  return head;
    
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
  
  display(move_last_element_to_front(head));
return 0;
}
