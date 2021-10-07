//Problem Link : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void dfs_visit(vector<int> adj[] , vector<int> &visited , stack<int> &stk , int i )  {
	    visited[i] = 1 ; 
	    for(auto ele : adj[i])  {
	        if(visited[ele] == 0 )  {
	            dfs_visit(adj , visited , stk , ele) ; 
	        }
	    }
	    stk.push(i) ;
	}
	
    void reverse_dfs(vector<int> adj[] , vector<int> &visited  , int i )  {
	    visited[i] = 1 ; 
	    for(auto ele : adj[i])  {
	        if(visited[ele] == 0 )  {
	            reverse_dfs(adj , visited , ele) ; 
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> stk ; 
        vector<int> visited(V , 0 ) ; 
        for(int i = 0 ; i < V ; i++)  {
            if(visited[i] == false )  
               dfs_visit(adj , visited ,stk ,  i )  ; 
        }
        
        for(int i = 0 ; i < V ; i++) 
           visited[i] = 0 ; 
           
        vector<int> mat[V] ; 
        for(int i = 0 ; i < V ; i++ )  {
            for(auto ele : adj[i]) {
                mat[ele].push_back(i) ;
            }
        }
        
        int count = 0 ; 
        while(stk.empty() == false )  {
            if(visited[stk.top()]==0)  {
                count++ ; 
                reverse_dfs(mat , visited , stk.top()) ; 
            }
            stk.pop() ; 
        }
        return count ; 
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
