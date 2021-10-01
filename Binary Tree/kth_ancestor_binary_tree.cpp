//problem link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor {
private:
    int LOG;
    vector<vector<int>> lift;
    
public:
    TreeAncestor(int n, vector<int>& parent) 
    {
        //constructor
        /*
        Approach: Binary Lifting
        For each node we will precompute its ancestor above him, its ancestor two nodes above, its ancestor four above, etc.
        Let's store them in the array left, i.e. lift[i][j] is the 2^j-th ancestor above the node i with i=1...N, j=0...ceil(log(N)).
        These information allow us to jump from any node to any ancestor above it in O(logN) time. We can compute this array using a 
        DFS traversal of the tree. 
        */
        LOG=0;
        
        while((1<<(LOG)) <=n){
            LOG++;
        }
        
        lift=vector<vector<int>>(n,vector<int>(LOG));
        
        //lift[v][i] => 2^ith ancestor of node v
        for(int i=0;i<n;i++){
            lift[i][0]=parent[i];   //1st ancestor
        }
        
         for(int k=1;k<LOG;k++)
        {
             for(int v=0;v<n;v++) 
             {
                 if(lift[v][k-1]<0) {
                     lift[v][k]=-1;      //if (2^k)th ancestor doesn't exist
                 }
                 else
                   lift[v][k]=lift[lift[v][k-1]][k-1];   //calculating ancestors recursively => DFS
             }
        }
        
        
    }
    
    int getKthAncestor(int node, int k) 
    {
       int i=0;
        int temp=node;
    
       while(i<=log2(k))   //just jumpting log2(k) steps to get kth ancester
       {
          if( k & (1<<i) ) 
          {
            temp=lift[temp][i];    //temp contains (2^i)th ancestor of itself
            
            if(temp==-1)       //if k is larger than height of node
                return -1;
          }
         i++;
      }
        return temp;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
