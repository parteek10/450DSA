//Method 1(Using BFS)
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> levelNode;
        if(!root)
            return ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> curNode=q.front();
            levelNode.insert({curNode.second,curNode.first->data});
            q.pop();
            if(curNode.first->left)
                q.push({curNode.first->left,curNode.second-1});
            if(curNode.first->right)
                q.push({curNode.first->right,curNode.second+1});
        }
        for(auto it=levelNode.begin();it!=levelNode.end();it++)
            ans.push_back(it->second);
        return ans;
    }
};

//Method 2(Using DFS)
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void traverse(Node* root,int spreadLevel,int verticalLevel,map<int,pair<int,int>>& spread)
    {
        if(root==nullptr)
            return;
        
        if(spread.find(spreadLevel)==spread.end())
            spread.insert({spreadLevel,{verticalLevel,root->data}});
        else
        {
            if(verticalLevel<spread[spreadLevel].first)
            {
                spread[spreadLevel].second=root->data;
                spread[spreadLevel].first=verticalLevel;
            }
        }
        traverse(root->left,spreadLevel-1,verticalLevel+1,spread);
        traverse(root->right,spreadLevel+1,verticalLevel+1,spread);
    }
    
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        //horizontal level, vertical level, value
        map<int,pair<int,int>> spread;
        int spreadLevel=0;
        int verticalLevel=0;
        traverse(root,spreadLevel,verticalLevel,spread);
        for(auto x: spread)
            ans.push_back(x.second.second);
        return ans;
    }
};