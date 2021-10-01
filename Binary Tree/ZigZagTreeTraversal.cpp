// Problem Link : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int> result ; 
	if(root==NULL) 
	  return result ; 
	  
	int size = 0 , flag = 1 ; 
	Node *front = NULL ; 
	
	queue<Node *> que ; 
	que.push(root) ; 
	
	while(que.empty()==false)  {
	    size = que.size() ; 
	    vector<int> temp ; 
	    while(size)  {
	        front = que.front() ; 
	        temp.push_back(front->data) ; 
	        que.pop() ; 
	            
            if(front->left != NULL ) 
              que.push(front->left) ; 
            if(front->right != NULL ) 
             que.push(front->right) ; 
	        
	        size-- ; 
	    }
	    
	    int n = temp.size() ; 
	    if(flag == 1 )  {
	        for(int i = 0 ; i < n ; i++) 
	           result.push_back(temp[i]) ; 
	    }
	    else {
	        for(int i = n-1 ; i>=0 ; i--)  
	           result.push_back(temp[i]) ; 
	    }
	    
	    flag = flag*(-1) ; 
	}
	
	return result ; 
	
}
