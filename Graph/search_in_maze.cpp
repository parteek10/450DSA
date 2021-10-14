//Q361) https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    int mat[7][7];
    string sol;
    
    void helper(vector<vector<int>> &m,int n,int row,int col,vector<string> &ans)
    {
        if(row>=n||col>=n||row<0||col<0||mat[row][col]==1||m[row][col]==0)
        {
            return;
        }
        if(row==n-1 && col==n-1)
        {
            //save path and return
            ans.push_back(sol);
            return;
        }
        
        mat[row][col]=1;

        sol.push_back('D');
        helper(m,n,row+1,col,ans);
        sol.pop_back();
        sol.push_back('L');
        helper(m,n,row,col-1,ans);
        sol.pop_back();
        sol.push_back('R');
        helper(m,n,row,col+1,ans);
        sol.pop_back();
        sol.push_back('U');
        helper(m,n,row-1,col,ans);
        sol.pop_back();
        mat[row][col]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                mat[i][j]=0;
            }
        }
        helper(m,n,0,0,ans);
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
