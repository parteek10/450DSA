//Problem Link : https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    int matrixOrder(int arr[] , vector<vector<int> > &dp , int i , int j )  {
        if(i == j ) 
           return 0 ; 
        if(i == j-1) 
            return dp[i][j] = arr[i-1]*arr[i]*arr[j] ; 
        if(dp[i][j] != INT_MAX) 
           return dp[i][j] ; 
        for(int k = i ; k<j ; k++)  {
            dp[i][j] = min(dp[i][j] , matrixOrder(arr , dp , i , k) + matrixOrder(arr , dp , k+1 , j) + arr[i-1]*arr[k]*arr[j]) ;
        }
        return dp[i][j] ; 
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        
        N = N-1 ;
        vector<vector<int> > dp(N+1 , vector<int>(N+1 , INT_MAX)) ; 
        return matrixOrder(arr , dp , 1 , N ) ;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
} 
