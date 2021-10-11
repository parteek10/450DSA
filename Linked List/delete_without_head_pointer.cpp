// C++ program to delete a node without head pointer
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void deleteNodeWithoutHead(struct Node* pos)
{
	if (pos == NULL) // If linked list is empty
		return;
	else {

		if (pos->next == NULL) {
			printf("This is last node, require head, can't "
				"be freed\n");
			return;
		}

		struct Node* temp = pos->next;

		pos->data = pos->next->data;

		pos->next = pos->next->next;

		free(temp);
	}
}

// Function to print the linked list
void print(Node* head)
{
	Node* temp = head;
	while (temp) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}

	cout << "NULL";
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node();
	new_node->data = new_data;

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


int main()
{
	
	struct Node* head = NULL;

	// create linked 35->15->4->20
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	cout << "Initial Linked List: \n";
	print(head);
	cout << endl << endl;

	Node* del = head->next;
	deleteNodeWithoutHead(del);

	// Printing the final linked list
	cout << "Final Linked List after deletion of 15:\n";
	print(head);

	return 0;

}

