//loop detection in a linked list
#include <bits/stdc++.h>
using namespace std;

// class for node of linkedlist
class Node {
public:
    int data;
    Node* next;
};

//creating the new node and linking
void insert_node(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}


bool detectLoop(Node* head)
{
    Node *slow, *fast;
    if(head==NULL||head->next==NULL)
        return false;
    slow=head;
    fast=head->next;
        
    while(slow!=fast&&slow!=NULL&&fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
    }
    if(slow==fast&&slow!=NULL)
        return true;
    else 
        return false;
}

int main()
{
    Node* head = NULL;

    insert_node(&head, 2);
    insert_node(&head, 5);
    insert_node(&head, 7);
    insert_node(&head, 86);

	//creating the loop
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found\n";
    else
        cout << "There is no loop\n";
        
    //without loop
    head->next->next->next->next = NULL;
    if (detectLoop(head))
        cout << "Loop found\n";
    else
        cout << "There is no loop\n";
    return 0;
}
