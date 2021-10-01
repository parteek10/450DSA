//problem link : https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include<bits/stdc++.h>
using namespace std ;
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int i , j , k ; 
        int dp[n+1] ; 
        dp[0] = 0 ; 
        for(i = 1 ; i<=n ; i++)  {
            dp[i] = INT_MIN ; 
            if(i-x >= 0 ) dp[i] = max(dp[i] ,1+ dp[i-x]) ; 
            if(i-y >= 0 ) dp[i] = max(dp[i] ,1+ dp[i-y]) ; 
            if(i-z >= 0 ) dp[i] = max(dp[i] ,1+ dp[i-z]) ; 
        }
        if(dp[n] <= 0 ) 
          return 0 ; 
        else 
          return dp[n] ; 
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
