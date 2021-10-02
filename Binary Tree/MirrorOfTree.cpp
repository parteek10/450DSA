// Problem link : https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/


// Approach 1: swap the links of left and right pointer for all nodes except leaf nodes
class Solution {
public:
    TreeNode* invertTree (TreeNode* root) {
        if (root == NULL) return NULL;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        root->right = invertTree(root->right);
        root->left = invertTree (root->left);
        return root;
     }
};

// Approach 2: call the function with two root nodes and reccurse it for left of original and right of new tree and vice versa

class Solution {
public:
    void invertHelper(TreeNode* r1, TreeNode* m) {
        if(r1->right) {
            m->left = new TreeNode(r1->right->val);
            TreeNode(r1->right, m->left);
        }
        if(r1->left) {
            m->right = new TreeNode(r1->left->val);
            TreeNode(r1->left, m->right);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* m = new TreeNode(root->val);
        invertHelper(root, m);
    }
};
