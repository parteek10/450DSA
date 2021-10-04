//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

};

//to make loop
void loopHere(Node* head, Node* tail, int position){
  if(position==0)
    return;
  Node* walk=head;
  for(int i=1; i<position; i++)
    walk=walk->next;
    tail->next=walk;
}

//to check loop
bool isLoop(Node* head){
  if(!head)
    return false;
  
  Node* fast=head->next;
  Node* slow=head;
  while(fast != slow){
    if(!fast || !fast->next;
       slow=slow->next;
  }
  return true;
}

//cal. the length       
int length(Node* head){
  int ret=0;
  while(head){
    ret++;
    head=head->next;
  }
  return ret;
}

//solution start from here
class Solution
{
    public:
    //finding the position of the loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            rem(head,fast);
        }
    }
  //remove the loop
    void rem(Node* head,Node* fast){
        if(fast==head){
            head=head->next;
            while(head->next!=fast)
            head=head->next;
            head->next=NULL;
            return;
        }
        while(fast->next!=head->next){
            fast=fast->next;
            head=head->next;
        }
        fast->next=NULL;
    }
};
       
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,num;
    cin>>n;
    
    Node *head,*tail;
    cin>>num;
    head=tail= new Node(num);
    for(int i=0; i< n-1 ; i++){
      cin>>num;
      tail->next= new Node(num);
      tail=tail->next;
    }
    
    int pos;
    cin>>pos;
    loopHere(head,tail,pos);
    
    Solution ob;
    ob.removeLoop(head);
    
    if(isLoop(head) || length(head)!=n)
      cout<<"0\n";
    else
      cout<<"1\n";
  }
  return 0;
}
