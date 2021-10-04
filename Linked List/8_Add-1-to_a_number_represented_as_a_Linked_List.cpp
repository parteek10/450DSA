//https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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

Node* Add_1_to_a_number(Node *head) 
    {
        int carry=add(head,1);
        if(carry==1){  // when we have to create node at head
            Node* x=new Node(1);
            x->next=head;
            head=x;
        }
        return head;
    }
//to add 1 to last element
    int add(Node* head,int carry){
        Node* temp=head;
            if(temp==NULL){
                carry=1;
                return carry;
            }
        temp->data=temp->data+add(temp->next,carry);
        
            if(temp->data==10){
                carry=1;
                temp->data=0;
            }
            else{
                carry=0;
            }
        return carry;
    }

int main(){
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,7);
    display(head);
  
  Add_1_to_a_number(head);
    display(head);
  
return 0;
}
