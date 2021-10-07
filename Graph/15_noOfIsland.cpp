#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int n , m ; 
     int x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int y[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
        
 
   void dfs(vector<vector<char>> &mat, int i, int j)
    {
        // int n = mat.size();
        // int m = mat[0].size();
        mat[i][j] = '2';
       
        
        for(int a=0; a<8; a++)
        {
            int ic = i+x[a];
            int jc = j+y[a];
            if(ic<n && ic>=0 && jc<m && jc>=0 && mat[ic][jc] == '1')
            {
                dfs(mat, ic, jc);
            }
        }
        return;
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        n = grid.size();
        if(n==0)
        {
            return 0;
        }
         m = grid[0].size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
