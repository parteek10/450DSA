#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long dp[10][26];
	int mat[4][3] ={{1,2,3,},
	         {4,5,6},
	         {7,8,9},
	         {-1,0,-1}};
	         
	long long solve(int i,int j,int n)
	{
	    if(n==1)
	      return 1;
	    if(dp[mat[i][j]][n]!=-1)
	       return dp[mat[i][j]][n];
	       
	   long long a,b=0,c=0,d=0,e=0;
	   // all five possibilities
	   a=solve(i,j,n-1);
	   if(i-1>=0 && mat[i-1][j]!=-1)
	     b=solve(i-1,j,n-1);
	   if(j-1>=0 && mat[i][j-1]!=-1)
	     c=solve(i,j-1,n-1);
	   if(i+1<4 && mat[i+1][j]!=-1)
	     d=solve(i+1,j,n-1);
	   if(j+1<3 && mat[i][j+1]!=-1)
	     e=solve(i,j+1,n-1);
	     
	  return dp[mat[i][j]][n]=a+b+c+d+e;
	  
	  
	}
	long long getCount(int n)
	{
		// Your code goes here
		for(int i=0;i<10;i++)
		{
		    for(int j=0;j<=n;j++)
		        dp[i][j]=-1;
		        
		}
		// calculate ans for every i,j
		long long ans=0;
		for(int i=0;i<4;i++)
		{
		   for(int j=0;j<3;j++)
		   {
		       if(mat[i][j]!=-1)
		          ans+=solve(i,j,n);
		          
		   }
		}
		
		return ans;
		
		
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
