// Problem Link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    int maxSum(vector<vector<int> > &dp , int wt[] , int val[]  , int n , int sum)  {
        if(sum == 0 || n == 0 ) 
          return 0 ; 
        if(dp[n][sum] != -1 ) 
          return dp[n][sum] ; 
        if(wt[n-1] <= sum ) 
           return dp[n][sum] = max(
               maxSum(dp , wt , val , n-1 , sum) , 
               val[n-1] + maxSum(dp , wt , val , n-1 , sum - wt[n-1])
            ) ;
        else {
            return dp[n][sum] = maxSum(dp , wt , val , n-1 , sum) ;
        }
    }
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   int dp[n+1][W+1] ; 
      vector<vector<int> > dp(n+1 , vector<int>(W+1 , -1)) ;
       return maxSum(dp , wt , val , n , W) ; 
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
