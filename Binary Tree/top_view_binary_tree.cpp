//problem link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


//main solution 
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
      /*
     Approach: 
     In order to get the top view of binary tree, we have to preform level order traversal by storing the elements and their positions in a map "mp".
     we have to make sure that we do not overright any value at a particular position on any above level if already present in the map.for any new 
     positions, we simpy add them to the map.Starting from root, our initial position is zero, if we go left, it decreases by 1 at each node and if
     we go right, it increases by one. The map automatically sorts on the basis of positions in increasing order and we return the result order.
     */
        map<int,int> mp;   //map to store node value and position
        vector<int> ans;
   
        if(root==NULL)
           return ans;
   
         queue<pair<Node*,int>> q;
         q.push({root,0});  //root's position is zero
           
           while(!q.empty())   //level order traversal
           {
               pair<Node*,int> x=q.front();
               q.pop();
               int val=(x.first)->data;
               int temp=x.second;
               
               if(mp.find(temp)==mp.end()) {   //current position doesnt exist in any top level
                   mp[temp]=val;   //added to map
               }
               
                if((x.first)->left)
                  q.push({(x.first)->left,temp-1});   //decreases by one going left
                
                if((x.first)->right)
                  q.push({(x.first)->right,temp+1});  //increases by one going right
           }
   
   
         for(auto it:mp) {
             ans.push_back(it.second);   //insert the node values into ans vector
         }
   
         return ans;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
