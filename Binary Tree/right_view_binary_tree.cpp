//problem link: https://leetcode.com/problems/binary-tree-right-side-view

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
/*
Approach: 
performing a normal level order traversal using queue "q".We are updating "prev" after each iteration to contain the previous element during traversal.
After the end of each level (when we get NULL), we are pushing the last element or leftmost element which is stored in "prev" of each level in "ans" vector.  
*/
        
        vector<int> ans;
        
        //return empty vector in case of empty tree
        if(root==NULL) 
            return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        int prev;   //to store prev element
        
        while(q.size()!=1) 
        {
            TreeNode *ptr=q.front();
            q.pop();
            
            if(ptr==NULL)   //end of level
            { 
                ans.push_back(prev);  //adding prev of last level to ans vector 
                q.push(NULL);
            }
            else {
                if(ptr->left)
                 q.push(ptr->left);
                if(ptr->right)
                 q.push(ptr->right);
                
                 prev=ptr->val;  //updating prev at each iteration
            }
               
        }
        
        //adding prev of last iteration to ans vector 
        ans.push_back(prev);
        
        return ans;
    } 
};
